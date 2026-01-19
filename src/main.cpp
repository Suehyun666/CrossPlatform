#include <stdio.h>
#include "../include/Processes.h"

int main(int argc, char *argv[]) {
    ProcessList processList;

    processList.Scan();

    for (int i = 0; i < processList.GetCount(); i++) {
        printf("%d %s\n",
            processList.GetPID(i),
            processList.GetName(i));
    }

    return 0;
}
