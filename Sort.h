
class Sort{
public:
    Sort();
    ~Sort();
    void vstav(int*);
    void vib(int*);
    void bubbleSort(int*);
};

Sort::Sort() {};

Sort::~Sort() {};

void Sort::vstav(int *arr){
    for(int i=1;i<10;i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j]){
                int x = arr[i];
                for(int k=i;k>j;k--){
                    arr[k] = arr[k-1];
                }
                arr[j] = x;
            }
        }
    }
}

void Sort::vib(int *arr){
    for(int i=0;i<9;i++){
        int tmp = i;
        for(int j=i+1;j<10;j++){
            if (arr[tmp] > arr[j])
                tmp = j;
        }
        if (arr[tmp] < arr[i]){
            int tmp2 = arr[i];
            arr[i] = arr[tmp];
            arr[tmp] = tmp2;
        }
    }
}

void Sort::bubbleSort(int *arr){
    for(int i = 0;i<9;i++){
        for (int j=0;j<9-i;j++){
            if (arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}