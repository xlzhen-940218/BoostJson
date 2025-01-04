#include "Json.h"

json::Json::Json()
{
}

json::Json::Json(std::string json)
{
	auto tmpValue = boost::json::parse(json.c_str());
	if (tmpValue.is_object())
	{
		data = tmpValue.as_object();
	}
	else
	{
		throw "json is not object";
	}

}

json::Json::Json(boost::json::object obj)
{
	data = obj;
}

json::Json::~Json()
{
}

std::string json::Json::toString()
{
	return boost::json::serialize(data).c_str();
}

boost::json::object json::Json::GetSelfObj()
{
	return data;
}

boost::json::value json::Json::GetValue(std::string key)
{
	if (key.size() > 0 && data.contains(key))
	{
		return data[key];
	}
	throw "key not exist!";
}


boost::json::object json::Json::GetObj(std::string key)
{
	auto value = GetValue(key);
	if (value.is_object())
	{
		return value.as_object();
	}
	throw "is not object!";
}

boost::json::array json::Json::GetArray(std::string key)
{
	auto value = GetValue(key);
	if (value.is_array())
	{
		return value.as_array();
	}
	throw "is not array!";
}

json::Json* json::Json::GetJsonObj(std::string key)
{
	auto obj = GetObj(key);
	return new Json(obj);
}

json::Json* json::Json::GetSelfJsonObj()
{
	auto obj = GetSelfObj();
	return new Json(obj);
}

json::JsonArray* json::Json::GetJsonArray(std::string key)
{
	auto array = GetArray(key);
	return new JsonArray(array);
}

bool json::Json::GetBool(std::string key)
{
	auto value = GetValue(key);
	if (value.is_bool())
	{
		return value.as_bool();
	}
	throw "is not bool!";
}

double json::Json::GetDouble(std::string key)
{
	auto value = GetValue(key);
	if (value.is_double())
	{
		return value.as_double();
	}
	throw "is not double!";
}

std::string json::Json::GetString(std::string key)
{
	auto value = GetValue(key);
	if (value.is_string())
	{
		return value.as_string().c_str();
	}
	throw "is not string!";
}

int64_t json::Json::GetInt64(std::string key)
{
	auto value = GetValue(key);
	if (value.is_int64())
	{
		return value.as_int64();
	}
	throw "is not int64!";
}

uint64_t json::Json::GetUInt64(std::string key)
{
	auto value = GetValue(key);
	if (value.is_uint64())
	{
		return value.as_uint64();
	}
	throw "is not uint64!";
}

void json::Json::PutJsonArray(std::string key, JsonArray* jsonArray)
{
	data[key.c_str()] = jsonArray->GetSelfArray();
}

void json::Json::PutJson(std::string key, Json* json)
{
	data[key.c_str()] = json->GetSelfObj();
}

void json::Json::PutObject(std::string key, boost::json::object value)
{
	data[key.c_str()] = value;
}

void json::Json::PutArray(std::string key, boost::json::array value)
{
	data[key.c_str()] = value;
}

void json::Json::PutBool(std::string key, bool value)
{
	data[key.c_str()] = value;
}

void json::Json::PutDouble(std::string key, double value)
{
	data[key.c_str()] = value;
}

void json::Json::PutString(std::string key, std::string value)
{
	data[key.c_str()] = value;
}

void json::Json::PutInt64(std::string key, int64_t value)
{
	data[key.c_str()] = value;
}

void json::Json::PutUInt64(std::string key, uint64_t value)
{
	data[key.c_str()] = value;
}


