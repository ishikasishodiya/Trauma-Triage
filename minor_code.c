

#include <stdio.h>
#define MAX 50

struct structure
{
    int gcs_sum;
    int patient_id;
};

void insert(int);
int length_of_queue = 0;
int delete(int);
int queue_array[MAX];
void ward_allotment(int queue_array[MAX]);
int rear = - 1;
int front = - 1;

void insert(int add_item)
{

    if (rear == MAX - 1)
    printf("Queue Overflow \n");
    else
    {
        if (front == - 1)
        /*If queue is initially empty */
        front = 0;
        rear = rear + 1;
        queue_array[rear] = add_item;
        length_of_queue+=1;
    }
} /* End of insert() */

int delete(int ward_no)
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return 0;
    }
    else
    {
        front = front + 1;
        return queue_array[front-1];
    }
} /* End of delete() */


void ward_allotment(int queue_array[MAX])
{   
    int q[50];
    int i,n, ward_no[4];
    label:
    printf("\n");
    printf("Number of wards empty: ");    //we assume we have 4 wards only
    scanf("%d",&n);
    if(n!=0)
    printf("Enter the ward number of %d wards which are empty(Ward 0,1,2,3):\n",n); // ward 1,2,3 or 4 (assistant will enter this)
    for(i = 0; i<n; i++)
    {
        scanf("%d",&ward_no[i]);
        q[i] = delete(ward_no[i]);
    }
    if(n!=0)
    {
    printf("\n");
    printf("|----------------------------------|\n");
    printf("|  Patient No.   |Ward No. allotted|\n");
    printf("|----------------------------------|\n");
    for(i = 0; i<n; i++)
    printf("|       %d        |          %d      |\n",q[i],ward_no[i]);
    printf("|----------------------------------|\n");
    printf("\n\n");
    }
   
    if(front<=rear)
    {
    printf("waiting queue of patients:\n");    
    printf("  Patient Id\n");
    for(i = front; i<=rear; i++)
    {
    printf("|-----------|\n");
    printf("|     %d     |\n", queue_array[i]);
    }
    printf("|-----------|\n");
    
    sleep(6);
    goto label;
    }
    
}



int main()
{
    int victims,i;
    printf("\n              +++++++++++++\n");
    printf("               + Welcome +\n");
    printf("              +++++++++++++\n\n");
    printf("Enter how many total victims are there:");
    scanf("%d",&victims);
    printf("\n");
    
    struct structure patients[victims];
    struct structure severe[victims+1];
    struct structure moderate[victims+1];
    struct structure mild[victims+1];
    
    
    int eye_open,motor,verbal_response, sum;
    int j, temp1, temp2;
    int index1=0, index2=0, index3=0;  //number of patients in severe, moderete and mild queues
    
   
          //patient number and GCS sum 
    for(i = 0; i<victims;i++)
    {
        printf("Enter the details of patient number %d:\n", i);
        printf("Scale of eye opening:");
        scanf("%d",&eye_open);
        printf("Scale of motor response:");
        scanf("%d",&motor);
        printf("Scale of verbal response:");
        scanf("%d",&verbal_response);
        sum = eye_open + motor + verbal_response;

        patients[i].gcs_sum = sum;
        patients[i].patient_id = i;
         printf("\n");
        
    }
   
    
    
    for(i = 0 ;i<victims-1; i++)            // sorting
    {
        for(j = 0 ;j<victims-i-1; j++)
        {
            if (patients[j].gcs_sum > patients[j+1].gcs_sum)
            {
                temp1 = patients[j].gcs_sum;
                temp2 = patients[j].patient_id;
                patients[j].gcs_sum = patients[j+1].gcs_sum;
                patients[j].patient_id = patients[j+1].patient_id;
                patients[j+1].gcs_sum= temp1;
                patients[j+1].patient_id= temp2;
            }
        }
    }
    
    printf("Final sorted list:\n");        //print final sorted queue
    printf("patient_id\tgcs_sum\n");
    for(i = 0 ;i<victims; i++)
    {
        printf("%d \t\t%d\n", patients[i].patient_id, patients[i].gcs_sum);
        
    }
    
    
    for(i=0; i<victims; i++)          //queues for moderete
    {
         if(patients[i].gcs_sum>=9 && patients[i].gcs_sum<=12)
        {
            moderate[index2].gcs_sum = patients[i].gcs_sum;
            moderate[index2].patient_id = patients[i].patient_id;
            index2 = index2 + 1;
            insert(patients[i].patient_id);
        }
    }
        
    for(i=0; i<victims; i++)          //queues for mild
    {
        if(patients[i].gcs_sum>=13)
        {
            mild[index3].gcs_sum = patients[i].gcs_sum;
            mild[index3].patient_id = patients[i].patient_id;
            index3 = index3 + 1;
            insert(patients[i].patient_id);
        }
        
    }
        
       
    for(i=0; i<victims; i++)          //queues for severe
    {
        if(patients[i].gcs_sum<=8)
        {
            severe[index1].gcs_sum = patients[i].gcs_sum;
            severe[index1].patient_id = patients[i].patient_id;
            index1 = index1 + 1;
            insert(patients[i].patient_id);
        }
        
    }
   
 
    printf("\n");                          // print different queues
    printf("\nsevere:\n");
    printf("patient_id\tgcs_sum\n");
    for(i = 0 ;i<index1; i++)
    {
        printf("%d \t\t%d\n", severe[i].patient_id, severe[i].gcs_sum);
    }
    
    printf("\n"); 
    printf("\nmoderate:\n");
    printf("patient_id\tgcs_sum\n");
    for(i = 0 ;i<index2; i++)
    {
        printf("%d \t\t%d\n", moderate[i].patient_id, moderate[i].gcs_sum);
    }
    
    printf("\n"); 
    printf("\nmild:\n");
    printf("patient_id\tgcs_sum\n");
    for(i = 0 ;i<index3; i++)
    {
        printf("%d \t\t%d\n", mild[i].patient_id, mild[i].gcs_sum);
    }
    
     
    ward_allotment(queue_array);
    printf("\nNo more Patients\n");
    printf("-----THANK YOU------");
     
 }

