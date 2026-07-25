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
    
    //emergencyProjects->SetTaskFinished(false);
    emergencyProjects->SetTaskFinished(true);

    emergencyProjects->WriteProgram();
    emergencyProjects->SetHour(19);
    emergencyProjects->WriteProgram();
    emergencyProjects->SetHour(22);
    emergencyProjects->WriteProgram();
    delete emergencyProjects;
    return 0;
}