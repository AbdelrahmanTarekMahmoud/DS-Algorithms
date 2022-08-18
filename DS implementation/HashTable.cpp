#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

class HashObject
{
public:
	HashObject(){}
	~HashObject(){}
	//Getters
	std::string& GetKey() { return key_; }
	std::string& GetValue() { return value_; }
	static const std::string GetDummyKey() { return "(DUMMY)"; }
	static const std::string GetNullKey() { return "(NULL)"; }
	//setters
	void SetAsDummy()
	{
		key_ = GetDummyKey();
		value_ = "";
	}
	void setKey(const std::string key) { key_ = key; }
	void setValue(const std::string value) { value_ = value; }
private:
	std::string key_;
	std::string value_;
};
class HashTable
{
public:
	HashTable(const int size);
	~HashTable();
	// Add the given key and object to hash table. If key exists, update the value
	void Add(HashObject* object);
	// Returns true if the given key exists in the table
	bool Exists(std::string key);
	// Returns the value associated with the given key, or NULL if it doesn't exist
	std::string Get(std::string key);
	// Removes the value associated with key from the table.
	void Remove(std::string key);
	// Outputs the content of the hash table for debugging purposes.
	void Display();
private:
	int size_;
	HashObject* data_;
	//Specify the used Hash Function
	int Hash(const std::string key);
};

HashTable::HashTable(const int size)
{
	size_ = size;
	data_ = new HashObject[size];
	for (int i = 0; i < size; i++)
	{
		data_[i].setKey(HashObject::GetNullKey());
	}
}

HashTable::~HashTable() { delete[] data_; }

int HashTable::Hash(const std::string key)
{
	int hash = 0; 
	for (int i = 0;i < key.length();++i)
	{
		hash = hash * 31 + key[i];
	}
	return abs(hash % size_);
}

bool HashTable::Exists(const std::string key)
{
	int index = Hash(key);
	int original_index = index;
	bool found = false;

	while (data_[index].GetKey() != HashObject::GetNullKey())
	{
		if (data_[index].GetKey() == key)
		{
			found = true;
			break;
		}
		index = (index + 1) % size_; // % here because we cant get out of indices border
		if (index == original_index)// we made a full circle so we didnt find it
		{
			break;
		}
	}
	return found;
}

void HashTable::Add(HashObject* object)
{
	int index = Hash(object->GetKey());
	int original_index = index;
	int dummyIndex = -1;
	bool found = false;

	while (data_[index].GetKey() != HashObject::GetNullKey())
	{
		if (data_[index].GetKey() == object->GetKey())
		{
			found = true;
			break;
		}
		else if (data_[index].GetKey() == HashObject::GetDummyKey())
		{
			dummyIndex = index;
		}
		index = (index + 1) % size_;
		if (index == original_index)
		{
			return;
		}
	}
	if (!found && dummyIndex != -1)
	{
		index = dummyIndex;
	}
	
	data_[index].setKey(object->GetKey());
	data_[index].setValue(object -> GetValue());
}

void HashTable::Display()
{
	for (int i = 0; i < size_;++i)
	{
		std::cout << i << ":" << data_[i].GetKey() << ":" << data_[i].GetValue() << std::endl;
	}
	std::cout << "**********************************************************" << std::endl;
}

void HashTable::Remove(std::string key)
{
	int index = Hash(key);
	int original_index = index;

	while (data_[index].GetKey() != HashObject::GetNullKey())
	{
		if (data_[index].GetKey() == key)
		{
			data_[index].setKey(HashObject::GetDummyKey());
			data_[index].setValue("");
			break;
		}
		index = (index + 1) % size_;
		if (index == original_index)
		{
			break;
		}
	}
}

std::string HashTable::Get(std::string key)
{
	int index = Hash(key);
	int original_index = index;

	while (data_[index].GetKey() != HashObject::GetNullKey())
	{
		if (data_[index].GetKey() == key)
		{
			return data_[index].GetValue();
		}
		index = (index + 1) % size_;
		if (index == original_index)
		{
			break;
		}
	}
	return NULL;
}

int main()
{
	HashTable HT(10);
	HashObject H1;
	H1.setKey("Abdelrahman");
	H1.setValue("VERY GOOD");
	HashObject H2;
	H2.setKey("Khaled");
	H2.setValue("GOOD");
	HashObject H3;
	H3.setKey("ElSayed");
	H3.setValue("Excellent");
	HashObject H4;
	H4.setKey("Romih");
	H4.setValue("VERY GOOD");
	HashObject H5;
	H5.setKey("Abyo");
	H5.setValue("FAIR");
	HashObject H6;
	H6.setKey("Wegz");
	H6.setValue("Fail");
	
	HT.Add(&H1);
	HT.Add(&H2);
	HT.Add(&H3);
	HT.Add(&H4);
	HT.Add(&H5);
	HT.Add(&H6);
	std::cout << HT.Exists("ElSayed") << std::endl;
	HT.Display();
	HT.Remove("Abyo");
	HT.Display();

	return 0;
}



