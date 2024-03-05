#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <format>

int parseMD(std::string filename)
{
    std::vector<std::string> lines;

    std::ifstream file(RESOURCES_PATH + filename);
    std::string line;

    int metadataEnd = 0;
    int publish = 0;

    std::ifstream t("file.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string fileContent = buffer.str();

    if (file.is_open())
    {
        while (std::getline(file, line) && metadataEnd < 2)
        {
            if (line == "---")
            {
                metadataEnd++;
                continue;
            }
            lines.push_back(line);
        }
        file.close();
    }
    if (metadataEnd < 2)
    {
        std::cerr << std::format("Metadata not found in {0}\n", filename);
        std::cerr << std::format("Failed to publish {0}\n", filename);
        return 1;
    }
    for (size_t i = 0; i < lines.size(); i++)
    {
        if (lines[i].find("publish") != std::string::npos && lines[i].substr(8).find("true") != std::string::npos)
        {
            publish = 1;
        }
    }
    if (!publish)
    {
        std::cerr << std::format("Failed to publish {0}\n", filename);
        return 1;
    }

    std::cout << std::format("Publishing markdown: {0}\n", filename);


    std::cout << "Published markdown\n";
    return 0;
}

int main()
{
    return parseMD("publish.md");
}
