#ifndef OPENMW_ESSIMPORTER_IMPORTER_H
#define OPENMW_ESSIMPORTER_IMPORTER_H

#include <string>

namespace ESSImport
{

    class Importer
    {
    public:
        Importer(const std::string& essfile, const std::string& outfile);

        void run();

        void compare();

    private:
        std::string mEssFile;
        std::string mOutFile;
    };

}

#endif
