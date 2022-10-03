#include<iostream>
#include<cstdlib>

using namespace std;

template<class type>
class arrayList{
    private:
        bool empty;
        type *list;
        int currentSize; //actualk currentSize of the array
        int maxSize; //Max amount of ellements that the arrat can have
        int elemCount;//element elemCount
    public:
        arrayList(){
            list = NULL;
            elemCount = 0;
            currentSize = 0;
            empty = true;
        }
        arrayList(int elemCount){
            this->elemCount = elemCount;
        }
        /*
        arrayList(const arrayList<type>& al){
            currentSize = al.currentSize; 
            elemCount = al.elemCount;
            empty = al.empty;
            list = new type[currentSize];
            for(int i = 0; i < elemCount; i++)
                list[i] = al.list[i];
        }
        */
        ~arrayList(){
            free (list);
        }
        void expandSize(){
            type* aux = NULL;
            if(currentSize < 1)
                currentSize = 1;
            else
                currentSize = currentSize << 1; 
            list = (type*) realloc(list, sizeof(type) * currentSize);
            /*
            aux = new type[currentSize];
            if(0 < elemCount){
                for(int i = 0; i < elemCount; i++){
                    aux[i] = list[i];
                }
            }
            list = aux;
            delete [] aux; 
            */
        }
        bool shrinkSize(){
            //cout << "alo" << endl;
            type* aux = NULL;
            if(1 < currentSize){
                currentSize = currentSize >> 1;
                aux = list;
                list = (type*) realloc(list, sizeof(type) * currentSize);
                /*
                aux = new type[currentSize];
                if(0 < elemCount){
                    for(int i = 0; i < elemCount; i++){
                        aux[i] = list[i];
                    }
                }
                list = aux;
                delete[] aux;
                */
            }
            else{
                if(0 < currentSize && list != NULL)
                    free(list);//delete [] list;
                list = NULL;
                empty = true;
            }
            return true;
        }
        //capacity
        int getCurrentSize() const{
            return currentSize;
        }
        int getElemCount() const{
            return elemCount;
        }
        void resize(const int &n){
            /*
            function that add n units of space to the array
            */ 
            cout << currentSize <<" " << n << endl;
            if(currentSize < n){
                while(currentSize < n){
                    expandSize();
                }
            }
            else{
                while(n < currentSize && n <= currentSize >> 1)
                    shrinkSize();
            }
            if(elemCount < n){
                for(int j = elemCount; j < n; j++)
                    list[j] = 0;
            }
            elemCount = n;
        }
        void reserve(const int &i){
            resize(i + elemCount);
        }
        void moveElements(int i, int n){
            cout << i << " " << n << endl; 
            for(int j = elemCount - 1; i < j ; j--){
                list[j] = list[j - 1];
            }
            list[i] = 0;
        }
        void gap(const int &i, const int &n = 1){
            if(-1 < i){
                if(elemCount < (i+n)){
                    resize(i + n);
                }
                else{
                    resize(elemCount + n);
                }
                moveElements(i , n);  
            } 
        }
        bool isEmpty() const{
            return empty;
        }
        //access
        type getFirst()const{
            if(1 < elemCount)
                return list[0];
            else
                return list[0];
        }
        type getLast() const{
            if(1 < elemCount)
                return list[elemCount - 1];
            else
                return list[0];
        }
        type at(int i) const{
            return list[i % elemCount];
        }
        type operator [] (int i)const {
            return at(i);
        }
        void print() const{
            if(!empty){    
                cout << "[";
                for(int i = 0; i < elemCount - 1; i++){
                    cout << list[i] << ", ";
                }
                cout << list[elemCount - 1] << "]" <<endl;
            }
        }
        //Modifiers
        void push(const type &elem){
            if(elemCount == currentSize){
                //cout << elemCount << endl;
                expandSize();
            }
            list[elemCount] = elem;
            elemCount = elemCount + 1;
            empty = false;
        }
        type pop(){
            elemCount = elemCount - 1;
            type val = list[elemCount];
            if(elemCount == currentSize >> 1)
                shrinkSize();
            return val;
        }
        void insert(int i, type elem){
            if(-1 < i){
                gap(i);
                list[i] = elem;
            }
        }
        void erase(const int &i){
            
        }
        /*
        void insert(const arrayList<type> &al, int i){
            if(-1 < i){
                int alcount = al.getElemCount();
                gap(i, alcount);
                for(int j = i; j = i + alcount; i++)
                    list[i] = al[j - i];
            }
        }*/
        
};

int main(){
    arrayList<int> al1, al2;
    
    
    //al2 = arrayList<int>(al1);
    
    /*
    al1.push(12);
    
    al1.resize(8);
    al1.print();

    al1.gap(5, 1);

    al1.print();
    al1.insert(12, 7);
    
    al1.print();
    al1.resize(8);
    al1.print();*/
    return 0;
}