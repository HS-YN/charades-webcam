/* Python embedding in C++
 * Heeseung Yun
 *
 * Code Reference
 * https://docs.python.org/3.6/extending/embedding.html
 * https://stackoverflow.com/questions/4307187/how-to-catch-python-stdout-in-c-code
 * https://stackoverflow.com/questions/39644907/errors-using-sys-from-python-embedded-in-c
 */


#include <Python.h>
#include <stdio.h>

using namespace std;

int main(int argc, char *argv[]) {
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    FILE* fd;

    // This is to handle unicode value error for sys.argv.
    // For more information, please refer to the third link provided above
    wchar_t **wargv;
    wargv = (wchar_t**)malloc(1*sizeof(wchar_t*));
    *wargv = (wchar_t*)malloc(6*sizeof(wchar_t));
    **wargv = L'argv1';

    // Exit if the locale is not valid
    if(program == NULL) {
        fprintf(stderr, "CANNOT DECODE ARGV[0]\n");
        exit(1);
    }

    fd = fopen("./charades_webcam.py", "r");
    if(fd == NULL)
        perror("ERROR!");

    Py_SetProgramName(program);

    Py_Initialize();

    PySys_SetArgv(argc, (wchar_t**)wargv);
    PyRun_SimpleString("import sys\n");
    PyRun_SimpleString("sys.path.append('/opt/conda/envs/object-detection/lib/python3.5/site-packages/')\n");
    PyRun_SimpleString("sys.path.append('$HOME/charades-webcam/')\n");
    PyRun_SimpleFile(fd, "charades_webcam.py");

    Py_Finalize();
    PyMem_RawFree(program);

    return 0;
}
