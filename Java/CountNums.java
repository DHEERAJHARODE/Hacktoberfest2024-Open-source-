package com.harsh;

import org.w3c.dom.ls.LSOutput;

import java.beans.PropertyEditorManager;

public class CountNums {
    public static void main(String[] args) {
        int n = 50;
        int count = 0;
        while (n>0)
        {
            int rem = n % 10;
            if (rem == 5) {
                count++;
            }
            n = n / 10;
        }
        System.out.println(count);
    }

}
