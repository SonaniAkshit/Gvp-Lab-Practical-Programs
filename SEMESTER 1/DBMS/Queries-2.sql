1)SELECT * from p where p_city='London';
2)SELECT PNAME,WEIGHT from p WHERE WEIGHT=(SELECT max(WEIGHT) from p);
3)SELECT PNAME,pno from p where COLOR='Red';
4)SELECT s.SNO,s.SNAME