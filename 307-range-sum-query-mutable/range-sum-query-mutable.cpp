class NumArray {
public:
   //here u need to write the snippet of the segment man 
   //build update and overlaping was also there 4n size 
    
        vector<int>tree; 
        vector<int>nums;
        int n;

        void build (int node,int start,int end){
            //mid nikalo here then left and right 
            //index are like 2*1i+1 and +2
            if(start==end){
                //return 
                tree[node]=nums[start];
            }
            else{
               int  mid=(start+end)/2;
                build(2*node+1,start,mid);
                build(2*node+2,mid+1,end); 

                //a NOTHER ALSO WILL LOOK BACK 
                tree[node]=tree[2*node+1]+tree[2*node+2]; 
            }

         }

         void updateTree(int node,int start, int end ,int index,int value){
            //so here first i have to  find it and ten update the other tree acoordinly
            //first the node in need then the value
            //particular node he chaiye so 
            if(start==end){
                //i reached my node 
                nums[index]=value;          
                tree[node]=value;
            }
            //other just recusively go deep and deep
            else{
                int mid=(start+end)/2;
                if(index<=mid){
                  updateTree(2*node+1,start,mid,index,value);   
                }
                else{
                  updateTree(2*node+2,mid+1,end,index,value);   
                }
                //after all that the node value will also update 
                tree[node]=tree[2*node+1]+tree[2*node+2];  
            }
         }

         int query(int node,int start,int end ,int left,int right){
            //3 cases are here of overlaping
            if(right<start or left>end) return 0; 
            if(left<=start and end<=right) return tree[node]; 
            //partial overlap 
            int mid=(start+end)/2;
            int lefts=query(2*node+1,start,mid,left,right);     
            int rights=query(2*node+2,mid+1,end,left,right);    

            return lefts+rights; 
         }
    
    NumArray(vector<int>& arr) {
        //here just a tree will be there 4n size i think and 
        nums=arr;
        n=nums.size();   

        if(n>0){
            tree.resize(n*4,0);
            build(0,0,n-1);
        }
    }
    
    void update(int index, int val) {
        updateTree(0,0,n-1,index,val);  
    }
    
    int sumRange(int left, int right) {
       //so i have already calulated the sum here in the nodes 0 to 2 like 
       return query(0,0,n-1,left,right);  
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */