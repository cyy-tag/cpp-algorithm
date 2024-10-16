#pragma once

bool is_prime(int n){
    bool flag = true;
    for(int i = 2;i<=n/i;i++){
        if(n%i==0){
            flag = false;
            break;
        }
    }
    return flag;
}

