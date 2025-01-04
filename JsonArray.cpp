#include "Json.h"


json::JsonArray::JsonArray()
{

}

json::JsonArray::JsonArray(std::string json)
{
	auto tmpValue = boost::json::parse(json.c_str());
	if (tmpValue.is_array())
	{
		data = tmpValue.as_array();
	}
	else 
	{
		throw "json is not array";
	}
	
}

json::JsonArray::JsonArray(boost::json::array array)
{
	data = array;
}

json::JsonArray::~JsonArray()
{
}

std::string json::JsonArray::toString()
{
	return boost::json::serialize(data).c_str();
}

boost::json::value json::JsonArray::GetValue(int index, std::string key)
{

	if (index >= 0 && data.size() > index) //没有key就直接返回某个坐标的对象
	{
		if (key.size() == 0)
		{
			return data[index];
		}
		else
		{
			return data[index].as_object()[key.c_str()];
		}
	}

	return nullptr;
}

boost::json::object json::JsonArray::GetObj(int index, std::string key)
{
	boost::json::object value;
	auto val = GetValue(index, key);
	if (!val.is_null() && val.is_object())
	{
		return val.as_object();
	}

	throw "index or key not found!";
}

boost::json::array json::JsonArray::GetSelfArray()
{
	return data;
}

boost::json::array json::JsonArray::GetArray(int index, std::string key)
{
	auto val = GetValue(index, key);
	if (!val.is_null() && val.is_array())
	{
		return val.as_array();
	}
	throw "index or key not found!";
}

json::Json* json::JsonArray::GetJsonObj(int index, std::string key)
{
	auto obj = GetObj(index,key);
	return new Json(obj);
}

json::JsonArray* json::JsonArray::GetSelfJsonArray()
{
	auto array = GetSelfArray();
	return new JsonArray(array);
}

json::JsonArray* json::JsonArray::GetJsonArray(int index, std::string key)
{
	auto array = GetArray(index, key);
	return new JsonArray(array);
}

bool json::JsonArray::GetBool(int index, std::string key)
{
	auto val = GetValue(index, key);
	if (!val.is_null() && val.is_bool())
	{
		return val.as_bool();
	}

	throw "index or key not found!";
}

double json::JsonArray::GetDouble(int index, std::string key)
{
	auto val = GetValue(index, key);
	if (!val.is_null() && val.is_double())
	{
		return val.as_double();
	}

	throw "index or key not found!";
}

std::string json::JsonArray::GetString(int index, std::string key)
{
	auto val = GetValue(index, key);
	if (!val.is_null() && val.is_string())
	{
		return val.as_string().c_str();
	}
	throw "index or key not found!";
}

int64_t json::JsonArray::GetInt64(int index, std::string key)
{
	auto val = GetValue(index, key);
	if (!val.is_null() && val.is_int64())
	{
		return val.as_int64();
	}
	throw "index or key not found!";
}

uint64_t json::JsonArray::GetUInt64(int index, std::string key)
{
	auto val = GetValue(index, key);
	if (!val.is_null() && val.is_uint64())
	{
		return val.as_uint64();
	}
	throw "index or key not found!";
}

size_t json::JsonArray::PutJson(std::string key, Json* json)
{
	boost::json::object item;
	item[key.c_str()] = json->GetSelfObj();
	data.push_back(item);
	return data.size() - 1;
}

size_t json::JsonArray::PutJsonArray(std::string key, JsonArray* jsonArray)
{
	boost::json::object item;
	item[key.c_str()] = jsonArray->GetSelfArray();
	data.push_back(item);
	return data.size() - 1;
}

size_t json::JsonArray::PutObject(std::string key, boost::json::object value)
{
	boost::json::object item;
	item[key.c_str()] = value;
	data.push_back(item);
	return data.size() - 1;
}

size_t json::JsonArray::PutArray(std::string key, boost::json::array value)
{
	boost::json::object item;
	item[key.c_str()] = value;
	data.push_back(item);
	return data.size() - 1;
}

size_t json::JsonArray::PutBool(std::string key, bool value)
{
	boost::json::object item;
	item[key.c_str()] = value;
	data.push_back(item);
	return data.size() - 1;
}

size_t json::JsonArray::PutDouble(std::string key, double value)
{
	boost::json::object item;
	item[key.c_str()] = value;
	data.push_back(item);
	return data.size() - 1;
}

size_t json::JsonArray::PutString(std::string key, std::string value)
{
	boost::json::object item;
	item[key.c_str()] = value;
	data.push_back(item);
	return data.size() - 1;
}

size_t json::JsonArray::PutInt64(std::string key, int64_t value)
{
	boost::json::object item;
	item[key.c_str()] = value;
	data.push_back(item);
	return data.size() - 1;
}

size_t json::JsonArray::PutUInt64(std::string key, uint64_t value)
{
	boost::json::object item;
	item[key.c_str()] = value;
	data.push_back(item);
	return data.size() - 1;
}

size_t json::JsonArray::PutJson(Json* json)
{
	data.push_back(json->GetSelfObj());
	return data.size() - 1;
}

size_t json::JsonArray::PutJsonArray(JsonArray* jsonArray)
{
	data.push_back(jsonArray->GetSelfArray());
	return data.size() - 1;
}

size_t json::JsonArray::PutObject(boost::json::object value)
{
	data.push_back(value);
	return data.size() - 1;
}

size_t json::JsonArray::PutArray(boost::json::array value)
{
	data.push_back(value);
	return data.size() - 1;
}

size_t json::JsonArray::PutBool(bool value)
{
	data.push_back(value);
	return data.size() - 1;
}

size_t json::JsonArray::PutDouble(double value)
{
	data.push_back(value);
	return data.size() - 1;
}

size_t json::JsonArray::PutString(std::string value)
{
	data.push_back(value.c_str());
	return data.size() - 1;
}

size_t json::JsonArray::PutInt64(int64_t value)
{
	data.push_back(value);
	return data.size() - 1;
}

size_t json::JsonArray::PutUInt64(uint64_t value)
{
	data.push_back(value);
	return data.size() - 1;
}

size_t json::JsonArray::GetSize()
{
	return data.size();
}

