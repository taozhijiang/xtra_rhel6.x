#include <gmock/gmock.h>
#include <string>

#include <tinyxml/pugixml.hpp>

using namespace ::testing;



static inline std::string XmlGetValueByPath(const pugi::xml_document& xml_doc, const std::string& path) {
    pugi::xpath_node xNode = xml_doc.select_single_node(path.c_str());
    std::string val = xNode.node().text().as_string();
    return val;
}

static inline std::string XmlGetValueByPath(const pugi::xml_document& xml_doc, const std::string& prefix, const std::string& item) {
    std::string path = prefix + item;
    return XmlGetValueByPath(xml_doc, path);
}


static int show_detail (const pugi::xml_document& xml_doc, const std::string& nodes_path ) {

    pugi::xpath_node_set nodes = xml_doc.select_nodes(nodes_path.c_str());
    int index = 0;
    for (pugi::xpath_node_set::const_iterator it = nodes.begin(); it != nodes.end(); ++it) {
        pugi::xpath_node node = *it;
        auto rnode = node.node();

        std::string Name   = rnode.child_value("Name");
        std::string Age    = rnode.child_value("Age");
        std::string Salary = rnode.child_value("Salary");
        std::string PrcSts = rnode.child_value("PrcSts");

        std::cout << index++ << ":" << Name << "|"
                  << Age << "|"
                  << Salary << "|"
                  << PrcSts << std::endl;
    }

    return 0;
}



TEST(Xml, ParseTest) {

    const std::string xmlsource = 
        "<Document xmlns=\"xtra_rhel6.x\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"> "
        "  <Summry> "
        "    <Country>CN</Country> "
        "    <Location>Guangdong, Shenzhen</Location> "
        "    <PostCode>610000</PostCode> "
        "    <SysCd>PersonInfo</SysCd> "
        "  </Summry> "
        "  <Persons> "
        "    <ChckDt>20181212</ChckDt> "
        "    <TtlCnt>00000004</TtlCnt> "
        "    <Person> "
        "      <Name>张三</Name> "
        "      <Age>20</Age> "
        "      <Salary>00060000</Salary> "
        "      <PrcSts>PR03</PrcSts> "
        "    </Person> "
        "    <Person> "
        "      <Name>李四</Name> "
        "      <Age>39</Age> "
        "      <Salary>00080000</Salary> "
        "      <PrcSts>PR04</PrcSts> "
        "    </Person> "
        "    <Person> "
        "      <Name>王二</Name> "
        "      <Age>40</Age> "
        "      <Salary>00100000</Salary> "
        "      <PrcSts>PR09</PrcSts> "
        "    </Person> "
        "    <Person> "
        "      <Name>麻子</Name> "
        "      <Age>31</Age> "
        "      <Salary>00380000</Salary> "
        "      <PrcSts>PR04</PrcSts> "
        "    </Person> "
        "  </Persons> "
        "</Document> ";

    pugi::xml_document xml_doc;
    xml_doc.load_buffer(xmlsource.c_str(), xmlsource.size());

    const std::string DocDir = "/Document/Summry/";
    
    ASSERT_THAT(XmlGetValueByPath(xml_doc, "/Document/Summry/Country"), Eq("CN"));
    ASSERT_THAT(XmlGetValueByPath(xml_doc, "/Document/Summry/", "Location"), Eq("Guangdong, Shenzhen"));
    ASSERT_THAT(XmlGetValueByPath(xml_doc, "/Document/Summry/", "SysCd"), Eq("PersonInfo"));
    ASSERT_THAT(XmlGetValueByPath(xml_doc, "/Document/Summry/", "SSSSS"), Eq(""));
    ASSERT_THAT(show_detail(xml_doc, "/Document/Persons/Person"), Eq(0));
}

