#include <iostream>
#include <cmath>
using namespace std;


int josephusFunction(int n)
{

    float checkForPowerOfTwo = log2(n);

    if(ceil(checkForPowerOfTwo)==floor(checkForPowerOfTwo))
    {
        return 1;
    }

    int winnerNumber;
    int grimReaper;
    int deadCounter = 0;
    int initialArray[n];

    //fill the array
    for(int i=1; i<=n; i++)
    {
        initialArray[i]=i;
    }

   //this is where the fun begins
    while(deadCounter!=n-1)
    {

        for (int i = 1; i <= n; i++)
        {

            if(initialArray[i]!=0)
            {
                grimReaper = i;
                while(true)
                {

                    grimReaper++;

                    if(grimReaper>n)
                    {
                        for(int g=1; g<=n; g++)
                        {
                            if (initialArray[g]!=0)
                            {
                                initialArray[g] = 0;
                                deadCounter++;
                                break;
                            }
                        }
                        break;
                    }

                    if (initialArray[grimReaper]!=0)
                    {
                        initialArray[grimReaper] = 0;
                        deadCounter++;
                        break;
                    }


                }

            }

        }

    }

    //game over. find the last man standing

    for(int w=1; w<=n; w++)
    {
        if(initialArray[w]!=0)
        {
            winnerNumber = initialArray[w];
            break;
        }
    }

    return winnerNumber;

}



int main()
{


    cout<<josephusFunction(16)<<endl;
    return 0;
}
