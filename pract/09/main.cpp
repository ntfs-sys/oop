#include <zip.h>
import std;

int main(int argc, char* argv[]) {
    if (argc < 3) return 1;
    
    int error = 0;
    zip* arch = zip_open(argv[1], ZIP_CREATE, &error);
    if (!arch) return 1;
    
    zip_source_t* source = zip_source_file(arch, argv[2], 0, 0);
    if (!source) {
        zip_close(arch);
        return 1;
    }
    
    const char* name = std::strrchr(argv[2], '/');
    if (!name) name = std::strrchr(argv[2], '\\');
    if (!name) name = argv[2];
    else name++;
    
    zip_file_add(arch, name, source, ZIP_FL_OVERWRITE);
    zip_close(arch);
    
    return 0;
}