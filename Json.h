#include "boost/json.hpp"
#pragma once
namespace json {
	class JsonArray;
	class Json
	{
	public:
		Json();
		Json(std::string json);
		Json(boost::json::object obj);
		~Json();

		std::string toString();

		boost::json::object GetSelfObj();

		boost::json::object GetObj(std::string key);
		boost::json::array GetArray(std::string key);

		Json* GetJsonObj(std::string key);
		Json* GetSelfJsonObj();
		JsonArray* GetJsonArray(std::string key);

		bool GetBool(std::string key);
		double GetDouble(std::string key);
		std::string GetString(std::string key);
		int64_t GetInt64(std::string key);
		uint64_t GetUInt64(std::string key);

		void PutJsonArray(std::string key, JsonArray* jsonArray);
		void PutJson(std::string key, Json* json);
		void PutObject(std::string key, boost::json::object value);
		void PutArray(std::string key, boost::json::array value);
		void PutBool(std::string key, bool value);
		void PutDouble(std::string key, double value);
		void PutString(std::string key, std::string value);
		void PutInt64(std::string key, int64_t value);
		void PutUInt64(std::string key, uint64_t value);
	private:
		boost::json::object data;

		boost::json::value GetValue(std::string key);

	};

	class JsonArray
	{
	public:
		JsonArray();
		JsonArray(std::string json);
		JsonArray(boost::json::array array);
		~JsonArray();

		std::string toString();

		boost::json::object GetObj(int index, std::string key);

		boost::json::array GetSelfArray();

		boost::json::array GetArray(int index, std::string key);

		Json* GetJsonObj(int index, std::string key);

		JsonArray* GetSelfJsonArray();

		JsonArray* GetJsonArray(int index, std::string key);

		bool GetBool(int index, std::string key);
		double GetDouble(int index, std::string key);
		std::string GetString(int index, std::string key);
		int64_t GetInt64(int index, std::string key);
		uint64_t GetUInt64(int index, std::string key);

		size_t PutJson(std::string key, Json* json);
		size_t PutJsonArray(std::string key, JsonArray* jsonArray);
		size_t PutObject(std::string key, boost::json::object value);
		size_t PutArray(std::string key, boost::json::array value);
		size_t PutBool(std::string key, bool value);
		size_t PutDouble(std::string key, double value);
		size_t PutString(std::string key, std::string value);
		size_t PutInt64(std::string key, int64_t value);
		size_t PutUInt64(std::string key, uint64_t value);

		size_t PutJson(Json* json);
		size_t PutJsonArray(JsonArray* jsonArray);
		size_t PutObject(boost::json::object value);
		size_t PutArray(boost::json::array value);
		size_t PutBool( bool value);
		size_t PutDouble( double value);
		size_t PutString(std::string value);
		size_t PutInt64( int64_t value);
		size_t PutUInt64(uint64_t value);

		size_t GetSize();
	private:
		boost::json::array data;

		boost::json::value GetValue(int index, std::string key);

	};
}

