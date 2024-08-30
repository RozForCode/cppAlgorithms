// general format for variable size sliding window problem
/*
while(j<size){calculations}
if(condition<k){j++}
elseif(condition==K){ans<-calculation;j++}
elseif(current>k){
while(current>k){remove calculation for i(currentWindowIndex);i++}
}
*/