#include <gmock/gmock.h>

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include <json/json.h>

using namespace ::testing;


TEST(JsonCpp, ParseTest) {

    const std::string jsData = 
		" { " 
		" 	\"id\": \"26696879\", " 
		" 	\"title\": \"你好，疯子！\", " 
		" 	\"originalTitle\": \"你好，疯子！\", " 
		" 	\"rating\": 6.8, " 
		" 	\"ratingCount\": 31764, " 
		" 	\"commentCount\": 16018, " 
		" 	\"wishCount\": 10199, " 
		" 	\"reviewCount\": 689, " 
		" 	\"collectCount\": null, " 
		" 	\"videoUrls\": [ " 
		" 		{ " 
		" 			\"title\": \"花絮：玩转疯人院特辑 (中文字幕)\", " 
		" 			\"url\": \"http://vt1.doubanio.com/201705051745/2d52991bd3949621886f4feae0708e61/view/movie/M/302080162.mp4\" " 
		" 		}, " 
		" 		{ " 
		" 			\"title\": \"MV：万茜演唱主题曲《礼物》 (中文字幕)\", " 
		" 			\"url\": \"http://vt1.doubanio.com/201705051745/2f8e8d92a3e63ff6ac6c6dd50f7ec46b/view/movie/M/302090439.mp4\" " 
		" 		}, " 
		" 		{ " 
		" 			\"title\": \"MV：陈嘉桦演唱同名推广曲 (中文字幕)\", " 
		" 			\"url\": \"http://vt1.doubanio.com/201705051745/da0e8e78c56214f485a41c81043a5006/view/movie/M/302080791.mp4\" " 
		" 		} " 
		" 	] " 
		" } ";
		
	Json::Value root;
	Json::Reader reader;
	reader.parse(jsData, root);
	ASSERT_THAT(root.isNull(), Eq(false));
	
	ASSERT_THAT(root["title"].isString(), Eq(true));
	ASSERT_THAT(root["title"].asString(), Eq("你好，疯子！"));
	
	ASSERT_THAT(root["rating"].isDouble(), Eq(true));
	ASSERT_THAT(root["rating"].asDouble(), DoubleEq(6.8));
	
	ASSERT_THAT(root["xxxxxxx"].isDouble(), Eq(false));
	
	
	const Json::Value& videoUrls = root["videoUrls"];
	ASSERT_THAT(videoUrls.isArray(), Eq(true));
	ASSERT_THAT(videoUrls.size(), Eq(3));
	
	
	for (size_t i = 0; i < videoUrls.size(); i++) {
		ASSERT_THAT( videoUrls[static_cast<Json::Value::ArrayIndex>(i)]["title"].isString() && 
					 videoUrls[static_cast<Json::Value::ArrayIndex>(i)]["url"].isString(), Eq(true));
		std::cout << videoUrls[static_cast<Json::Value::ArrayIndex>(i)]["title"].asString() << "; " 
				  << videoUrls[static_cast<Json::Value::ArrayIndex>(i)]["url"].asString() << std::endl;
	}
}

TEST(JsonCpp, BuildTest) {
	
	std::map<std::string, int> persons = {
		{ "tao", 23 },
		{ "zhijiang", 111 },
		{ "nicol", 88 },
	};
	
	Json::Value root;
	
	root["info"] = "person infos";
	root["count"] = static_cast<int>(persons.size());
	Json::Value details;
	for(auto iter = persons.cbegin(); iter != persons.cend(); ++iter) {
		Json::Value item;
		item["name"] = iter->first;
		item["age"]  = iter->second;
		
		details.append(item);
	}
	root["details"] = details;
	
	Json::FastWriter fast_writer;
	std::string strJson = fast_writer.write(root);
	
	ASSERT_THAT(strJson.size() > 20, Eq(true));
	ASSERT_THAT(strJson.find("zhijiang") != std::string::npos, Eq(true));
	
	std::cout << "Final Marshal Json: " << strJson << std::endl;
}
