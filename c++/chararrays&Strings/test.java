
void change(int arr[]){
    arr = null;
    System.out.println(arr);
}

void main(){
    int arr[] = {10 , 20 , 30};
    System.out.println(arr);
    change(arr);
    System.out.println(arr);    
}