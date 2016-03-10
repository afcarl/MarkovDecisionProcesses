#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2016 vishalapr <vishalapr@vishalapr-Lenovo-G50-70>
#
# Distributed under terms of the MIT license.

"""

"""

maps = [[2,2,2,2,2,2],[2,0,0,1,0,2],[2,0,-1,2,0,2],[2,0,0,0,0,2],[2,2,2,2,2,2]]

probdir = 0.8
probper = 0.1

for j in range(1,13):
    j_row = (j-1)/4+1
    j_col = (j-1)%4+1
    for i in range(1,13):
        cur_row = (i-1)/4+1
        cur_col = (i-1)%4+1
        old_row = cur_row
        old_col = cur_col
        for dirs in range(1,6):
            ans = 0
            cur_row = old_row
            cur_col = old_col
            if cur_row == j_row and cur_col == j_col:
                ans = 1
            if maps[cur_row][cur_col]!=0:
                if dirs==5: #Noop action which leads to nowhere, probability is 1
                    print 0, #What should I do here ans-1 or 0?
                continue;
            if dirs==1:
                cur_row = old_row
                cur_col = old_col
                cur_row-=1
                if maps[cur_row][cur_col]==2:
                    cur_row+=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probdir
                cur_row = old_row
                cur_col = old_col
                cur_col+=1
                if maps[cur_row][cur_col]==2:
                    cur_col-=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probper
                cur_row = old_row
                cur_col = old_col
                cur_col-=1
                if maps[cur_row][cur_col]==2:
                    cur_col+=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probper
                #print cur_row,cur_col,'oy'
                print ans,
            if dirs==2:
                cur_row = old_row
                cur_col = old_col
                cur_row+=1
                if maps[cur_row][cur_col]==2:
                    cur_row-=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probdir
                cur_row = old_row
                cur_col = old_col
                cur_col+=1
                if maps[cur_row][cur_col]==2:
                    cur_col-=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probper
                cur_row = old_row
                cur_col = old_col
                cur_col-=1
                if maps[cur_row][cur_col]==2:
                    cur_col+=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probper
                #print cur_row,cur_col,'oy1'
                print ans,
            if dirs==3:
                cur_row = old_row
                cur_col = old_col
                cur_col-=1
                if maps[cur_row][cur_col]==2:
                    cur_col+=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probdir
                cur_row = old_row
                cur_col = old_col
                cur_row+=1
                if maps[cur_row][cur_col]==2:
                    cur_row-=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probper
                cur_row = old_row
                cur_col = old_col
                cur_row-=1
                if maps[cur_row][cur_col]==2:
                    cur_row+=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probper
                #print cur_row,cur_col,'oy2'
                print ans,
            if dirs==4:
                cur_row = old_row
                cur_col = old_col
                cur_col+=1
                if maps[cur_row][cur_col]==2:
                    cur_col-=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probdir
                cur_row = old_row
                cur_col = old_col
                cur_row+=1
                if maps[cur_row][cur_col]==2:
                    cur_row-=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probper
                cur_row = old_row
                cur_col = old_col
                cur_row-=1
                if maps[cur_row][cur_col]==2:
                    cur_row+=1
                if cur_row==j_row and cur_col==j_col:
                    ans-=probper
                #print cur_row,cur_col,'oy3'
                print ans,
    print ''
