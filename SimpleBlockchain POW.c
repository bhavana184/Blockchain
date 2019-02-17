//advance a bit
#include<stdio.h>//standard input output fns
#include<string.h>//for string functions
#include<unistd.h>//for hashing functions related to blockchain
#include<stdlib.h>//for standard library functions
#include<conio.h>

typedef struct{//making a structure for the blockchain
char data[256];
int prevHash;//hash of previous block
int hash;//current hash;hash means a digital signature which changes for different data
int nonce;//related to proof of work
}Block;

int hash(char data[])//hash algorithm is a function that converts any data string to numeric string of fixed length
{
    int i;
    int hash = 0;
    for(i=0;i<strlen(data);i++)
    {
        hash=hash^data[i];//doing xor operation with data
        hash=hash*2;//any random operation
    }
    return hash;
}
/*PART1
int mine_block(char data[])//for mining the block in proof of work,nonce is for that purpose
{
    int nonce=0;
    int hash1;
    char dataToHash[256];
    while(1)//1 means true
    {
      sprintf(dataToHash,"%s%d",data,nonce);
      hash1=hash(dataToHash);
      if((hash1&&0xff)==0xAA)//MSB==LSB
        {return nonce;
        }
        nonce++;
        printf("%x\n",hash1);
    }
    return nonce;
}
*/
//driver program
int main()
{
    int countblock=0;
Block block1;
strcpy(block1.data,"Block1 Name: B1");
block1.prevHash=0;//previous hash of very first block is 0
char dataToHash[256];
sprintf(dataToHash,"%s%d",block1.data,block1.prevHash);
block1.hash=hash(dataToHash);//generating block1 hash//PART3
countblock++;//PART3
printf("Block1\nBlock Data : %s\nPrevious Hash : %x\nCurrent Hash : %x\n",block1.data,block1.prevHash,block1.hash);//PART3//display current hash and previous hash as hexadecimal rather than integer
//getting and printing nonce value.seeing the suitable hashes
//PART2
/*block1.nonce=mine_block(dataToHash);
char dataToHashN[256];
sprintf(dataToHashN,"%s%d",dataToHash,block1.nonce);
block1.hash=hash(dataToHashN);
countblock++;
printf("Block1\nBlock Data : %s\nPrevious Hash : %x\nCurrent Hash : %x\n",block1.data,block1.prevHash,block1.hash);//display current hash and previous hash as hexadecimal rather than integer
printf("\nblock1 nonce : ",block1.nonce);*/

Block block2;
strcpy(block2.data,"Block2 Name: B2");
block2.prevHash=block1.hash;//previous hash of very second block is hash of first block
char dataToHash1[256];//dataToHash has to be renamed
sprintf(dataToHash1,"%s%d",block2.data,block2.prevHash);
block2.hash=hash(dataToHash1);//generating block1 hash
countblock++;
printf("\nBlock2\nBlock Data : %s\nPrevious Hash : %x\nCurrent Hash : %x\n",block2.data,block2.prevHash,block2.hash);//%x for represnting  hash no. in hexadecimal

Block block3;
strcpy(block3.data,"Block3 Name: B3");
block3.prevHash=block2.hash;//previous hash of very third block is hash of second block
char dataToHash2[256];//dataToHash has to be renamed
sprintf(dataToHash2,"%s%d",block3.data,block3.prevHash);
block3.hash=hash(dataToHash2);//generating block1 hash
countblock++;
printf("\nBlock3\nBlock Data : %s\nPrevious Hash : %x\nCurrent Hash : %x\n",block3.data,block3.prevHash,block3.hash);

if(block1.hash==block2.prevHash)printf("\nBlocks are successfully linked as Current Hash of previous block is equal to Previous Hash of current block");
printf("\nTotal no. of blocks created : %d",countblock);
getch();
return 0;
}
