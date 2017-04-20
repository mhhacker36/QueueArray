//Implementation of Queues using Arrays
//Circular arrays and resizing.
//Successfully Implementated 5:23 PM 4/1/2017
//I quited it two hours ago, at 3:15 PM 4/1/2017
//I'm so cool. LOL
#include <iostream>

using namespace std;

class QueueArray{
	string *list;
	int start, last, len, i, j, size_arr;
	public:
		void enqueue(string word){
			if(IsFull()){
				last = size_arr - 1;
				resize_arr(len*2);
			}
			last = (last + 1) % len;
			list[last] = word;
			size_arr++;
		}
		void dequeue(){
			if(IsEmpty()){
				cout<<"\nQueue Empty\n";
				return;
			}
			start++;
			size_arr--;
			if(size_arr == len/4){
				shrink_arr(len/2);
			}
		}
		bool IsEmpty(){
			return (size_arr == 0);
		}
		bool IsFull(){
			return (size_arr == len);
		}
		string top(){
			if(IsEmpty())
				return "\nEmpty Queue";
			return list[start];//I wrote it list[last - 1], which is for stacks, dumb me. But i debugged it myself
			//so intelect neutralized ;-)
		}
		void shrink_arr(int new_shrink_size){
			string *shrinked_arr;
			shrinked_arr = new string[new_shrink_size];//Half of length is passed here.
			for(i = 0, j = start;i < new_shrink_size/2;i++, j = (j+1)%len){//J is used to traverse the circular array
				shrinked_arr[i] = list[j];
			}
			start = 0;
			//delete list;
			list = shrinked_arr;
			len /= 2;
		}
		void resize_arr(int new_size){
			string *new_list;
			new_list = new string[new_size];//Double the length is passed here.
			for(i = 0, j = start;i < new_size/2;i++, j = (j+1)%len){//J is used to get the element of the circular array.
				new_list[i] = list[j];
			}
			start = 0;
			//delete list;
			list = new_list;
			len *= 2;
		}
		QueueArray(int size){
			start = 0;
			last = 0;
			size_arr = 0;
			len = size;
			list = new string[len];
		}
};
//Client Code
int main(){
	int len;
	cout<<"\nEnter the size: ";
	cin>>len;
	QueueArray S(len);
	cout<<"\nEnter word and enter - for popping: ";
	string word;
	cin>>word;
	while(word != "-1"){
		if(word == "-"){
			cout<<S.top()<<"\n";
			S.dequeue();	
		}
		else
			S.enqueue(word);
		cin>>word;
	}
	return 0;
}
