#include "work.h"

int main()
{
    Work *emergencyProjects = new Work();
    emergencyProjects->SetHour(9);
    emergencyProjects->WriteProgram();
    emergencyProjects->SetHour(10);
    emergencyProjects->WriteProgram();
    emergencyProjects->SetHour(12);
    emergencyProjects->WriteProgram();
    emergencyProjects->SetHour(13);
    emergencyProjects->WriteProgram();
    emergencyProjects->SetHour(14);
    emergencyProjects->WriteProgram();

    emergencyProjects->SetHour(17);
    emergencyProjects->WriteProgram();
    
    //emergencyProjects->SetTaskFinished(true);
    emergencyProjects->SetTaskFinished(false);

    emergencyProjects->WriteProgram();
    emergencyProjects->SetHour(19);
    emergencyProjects->WriteProgram();
    emergencyProjects->SetHour(22);
    emergencyProjects->WriteProgram();
    delete emergencyProjects;
    return 0;
}