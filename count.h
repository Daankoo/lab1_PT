#pragma once 

int count(int yr, int mn, int da) {
    mn -= 2;
    if (mn <= 0) {
        mn += 12;
        yr--;
    }
    mn = mn * 83 / 32;
    mn += da;
    mn += yr;
    mn += yr / 4;
    mn -= yr / 100;
    mn += yr / 400;
    
    return mn % 7;
}