#include <stdio.h>
#include <pthread.h>

// Function executed by the thread
void* threadFunction(void* arg) {
    printf("Hello from the thread! Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t thread;

    // Create the thread
    int result = pthread_create(&thread, NULL, threadFunction, NULL);
    if (result != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for the thread to finish execution
    pthread_join(thread, NULL);

    printf("Main thread completed.\n");

    return 0;
}

------------------------------------------------

#include <stdio.h>  
#define MAX_PROCESSES 10  
#define MAX_RESOURCES 10  
  
int allocation[MAX_PROCESSES][MAX_RESOURCES];  
int request[MAX_PROCESSES][MAX_RESOURCES];  
int available[MAX_RESOURCES];  
int resources[MAX_RESOURCES];  
int work[MAX_RESOURCES];  
int marked[MAX_PROCESSES];  
  
int main() {  
 int num_processes, num_resources;  
  
 printf("Enter the number of processes: ");  
 scanf("%d", &num_processes);  
  
 printf("Enter the number of resources: ");  
 scanf("%d", &num_resources);  
  
 // Input total resources  
 for (int i = 0; i < num_resources; i++) {  
 printf("Enter the total amount of Resource R%d: ", i + 1);  
 scanf("%d", &resources[i]);  
 }  
  
 // Input request matrix  
 printf("Enter the request matrix:\n");  
 for (int i = 0; i < num_processes; i++) {  
 for (int j = 0; j < num_resources; j++) {  
 scanf("%d", &request[i][j]);  
 }  
 }  
  
 // User Input allocation matrix  
 printf("Enter the allocation matrix:\n");  
 for (int i = 0; i < num_processes; i++) {  
 for (int j = 0; j < num_resources; j++) {  
 scanf("%d", &allocation[i][j]);  
 }  
 }  
  
 // Initialization of the available resources  
 for (int j = 0; j < num_resources; j++) {  
 available[j] = resources[j];  
 for (int i = 0; i < num_processes; i++) {  
 available[j] -= allocation[i][j];  
 }  
 }  
  
 // Mark processes with zero allocation  
 for (int i = 0; i < num_processes; i++) {  
 int count = 0;  
 for (int j = 0; j < num_resources; j++) {  
 if (allocation[i][j] == 0) {  
 count++;  
 } else {  
 break;  
 }  
 }  
 if (count == num_resources) {  
 marked[i] = 1;  
 }  
 }  
  
 // Initialize work with available  
 for (int j = 0; j < num_resources; j++) {  
 work[j] = available[j];  
 }  
  
 // Mark processes with requests <= work  
 for (int i = 0; i < num_processes; i++) {  
 int can_be_processed = 1;  
 if (marked[i] != 1) {  
 for (int j = 0; j < num_resources; j++) {  
 if (request[i][j] > work[j]) {  
 can_be_processed = 0;  
 break;  
 }  
 }  
 if (can_be_processed) {  
 marked[i] = 1;  
 for (int j = 0; j < num_resources; j++) {  
 work[j] += allocation[i][j];  
 }  
 }  
 }  
 }  
  
 // Check for unmarked processes (deadlock)  
 int deadlock = 0;  
 for (int i = 0; i < num_processes; i++) {  
 if (marked[i] != 1) {  
 deadlock = 1;  
 break;  
 }  
 }  
  
 if (deadlock) {  
 printf("Deadlock detected\n");  
 } else {  
 printf("No deadlock possible\n");  
 }  
  
 return 0;  
} 

--------------------------------------------

#include<stdio.h>
int main()
{
int i,j,bt[10],t,n,wt[10],tt[10],w1=0,t1=0;
float aw,at;
printf("enter no. of processes:\n");
scanf("%d",&n);
printf("enter the brust time of processes:");
for(i=0;i<n;i++)
scanf("%d",&bt[i]);
for(i=0;i<n;i++)
{
	for(j=i;j<n;j++)
	if(bt[i]>bt[j])
	{
		t=bt[i];
        bt[i]=bt[j];
        bt[j]=t;
	}
}
for(i=0;i<n;i++)
printf("%d",bt[i]);
for(i=0;i<n;i++)
{
wt[0]=0;
tt[0]=bt[0];
wt[i+1]=bt[i]+wt[i];
tt[i+1]=tt[i]+bt[i+1];
w1=w1+wt[i];
t1=t1+tt[i];
}
aw=w1/n;
at=t1/n;
printf("\nbt\t wt\t tt\n");
for(i=0;i<n;i++)
printf("%d\t %d\t %d\n",bt[i],wt[i],tt[i]);
printf("aw=%f\n,at=%f\n",aw,at);
}

-----------------------------------

#include <stdio.h>  
int main()  
{  
    int incomingStream[] = {4 , 1 , 2 , 4 , 5};  
    int pageFaults = 0;  
    int frames = 3;  
    int m, n, s, pages;   
    pages = sizeof(incomingStream)/sizeof(incomingStream[0]);   
    printf(" Incoming \ t Frame 1 \ t Frame 2 \ t Frame 3 ");  
    int temp[ frames ];  
    for(m = 0; m < frames; m++)  
    {  
        temp[m] = -1;  
    }  
    for(m = 0; m < pages; m++)  
    {  
        s = 0;   
        for(n = 0; n < frames; n++)  
        {  
            if(incomingStream[m] == temp[n])  
            {  
                s++;  
                pageFaults--;  
            }  
        }  
        pageFaults++;  
        if((pageFaults <= frames) && (s == 0))  
        {  
            temp[m] = incomingStream[m];  
        }  
        else if(s == 0)  
        {  
            temp[(pageFaults - 1) % frames] = incomingStream[m];  
        }  
        printf("\n");  
        printf("%d\t\t\t",incomingStream[m]);  
        for(n = 0; n < frames; n++)  
        {  
            if(temp[n] != -1)  
                printf(" %d\t\t\t", temp[n]);  
            else  
                printf(" - \t\t\t");  
        }  
    }  
    printf("\nTotal Page Faults:\t%d\n", pageFaults);  
    return 0;  
}  

------------------------------------------

#include<stdio.h>
int main()
{
int st[10],bt[10],wt[10],tat[10],n,tq;
int i,count=0,swt=0,stat=0,temp,sq=0;
float awt=0.0,atat=0.0;
printf("Enter number of processes:");
scanf("%d",&n);
printf("Enter burst time for sequences:");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
st[i]=bt[i];
}
printf("Enter time quantum:");
scanf("%d",&tq);
while(1)
{
for(i=0,count=0;i<n;i++)
{
temp=tq;
if(st[i]==0)
{
count++;
continue;
}
if(st[i]>tq)
st[i]=st[i]-tq;
else
if(st[i]>=0)
{
temp=st[i];
st[i]=0;
}
sq=sq+temp;
tat[i]=sq;

}
if(n==count)
break;
}
for(i=0;i<n;i++)
{
wt[i]=tat[i]-bt[i];
swt=swt+wt[i];
stat=stat+tat[i];
}
awt=(float)swt/n;
atat=(float)stat/n;
printf("Process_no Burst time Wait time Turn around time");
for(i=0;i<n;i++)
printf("\n%d\t %d\t %d\t %d",i+1,bt[i],wt[i],tat[i]);
printf("\nAvg wait time is %f Avg turn around time is %f",awt,atat);
}

-------------------------------------------

#include<stdio.h>
 
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    
    printf("Enter page reference string: ");
    
    for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);
    }
    
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
        	flag3 =0;
        	
            for(j = 0; j < no_of_frames; ++j){
            	temp[j] = -1;
            	
            	for(k = i + 1; k < no_of_pages; ++k){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
            			break;
            		}
            	}
            }
            
            for(j = 0; j < no_of_frames; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            
            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < no_of_frames; ++j){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			
			frames[pos] = pages[i];
			faults++;
        }
        
        printf("\n");
        
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;
}

------------------------------------------------------------

#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,req[50],mov=0,cp;
    printf("enter the current position\n");
    scanf("%d",&cp);
    printf("enter the number of requests\n");
    scanf("%d",&n);
    printf("enter the request order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    mov=mov+abs(cp-req[0]); // abs is used to calculate the absolute value
    printf("%d -> %d",cp,req[0]);
    for(i=1;i<n;i++)
    {
        mov=mov+abs(req[i]-req[i-1]);
        printf(" -> %d",req[i]);
    }
    printf("\n");
    printf("total head movement = %d\n",mov);
}

-----------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t chopstick[5];

void * philosopher(void *);
void eat(int);
int main()
{
	int i,a[5];
	pthread_t tid[5];
	
	sem_init(&room,0,4);
	
	for(i=0;i<5;i++)
		sem_init(&chopstick[i],0,1);
		
	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}

void * philosopher(void * num)
{
	int phil=*(int *)num;

	sem_wait(&room);
	printf("\nPhilosopher %d has entered room",phil);
	sem_wait(&chopstick[phil]);
	sem_wait(&chopstick[(phil+1)%5]);

	eat(phil);
	sleep(2);
	printf("\nPhilosopher %d has finished eating",phil);

	sem_post(&chopstick[(phil+1)%5]);
	sem_post(&chopstick[phil]);
	sem_post(&room);
}

void eat(int phil)
{
	printf("\nPhilosopher %d is eating",phil);
}

