#include <iostream>
#include "lidar/include/TIM561.h"

int main() {
    std::cout << "Connection..." << std::endl;
    TIM561 tim;
    if( tim.connect("192.168.1.93",2112) ) {
        std::cout << "Connected" << std::endl;
        if( tim.start() )
        {
            std::cout << "Started" << std::endl;
            while(true)
            {
                usleep(70000);
                tim.update();
                auto tmp = tim.getDataPoints();
                for( int i = 0 ; i< TIM561::NBR_DATA ; i+=1 )
                {
//                    if( tmp[i].distance < 500 )
//                        printf("|");
//                    else
//                        printf(".");

                    printf("[%g, %d] ", tmp[i].angle, tmp[i].distance);
                }
                printf("\n\n");
            }
        }
    }
    tim.close();
    return 0;
}