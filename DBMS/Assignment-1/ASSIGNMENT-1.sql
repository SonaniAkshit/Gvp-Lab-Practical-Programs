*QUE-1*
=======
CREATE TABLE s( sno char(3) Primary key, sname varchar(50), s_status int, s_city varchar(25) );

	insert into s values('s1','Smith',20,'London');
	insert into s values('s2','Jones',10,'Paris');
	insert into s values('s3','Blake',10,'Paris');
	insert into s values('s4','Clark',20,'London');
	insert into s values('s5','Adams',30,'Athens');

CREATE table p( pno char(3) primary key, pname varchar(20), color varchar(10), wight float(5.2), p_city varchar(25) );

	insert into p values('p1','Nut','Red',12.0,'London');
	insert into p values('p2','Bolt','Green',17.0,'Paris');
	insert into p values('p3','Screw','Blue',17.0,'Oslo');
	insert into p values('p4','Screw','Red',14.0,'London');
	insert into p values('p5','Cam','Blue',12.0,'Paris');
	insert into p values('p6','Cg','Red',19.0,'London');
	
CREATE table sp( sno char(30), pno char(3), qty int,PRIMARY key(sno,pno),FOREIGN KEY(sno) REFERENCES s(sno) ,FOREIGN KEY(pno) REFERENCES p(pno));
ALTER TABLE `mca2024akshit`.`sp` DROP INDEX `pno`, ADD INDEX `pno` (`pno`, `sno`) USING BTREE;
	insert into sp values('s1','p1',300);
	insert into sp values('s1','p2',200);
	insert into sp values('s1','p3',400);
	insert into sp values('s1','p4',200);
	insert into sp values('s1','p5',100);
	insert into sp values('s1','p6',100);
	insert into sp values('s2','p1',300);
	insert into sp values('s2','p2',400);
	insert into sp values('s3','p2',200);
	insert into sp values('s4','p2',200);
	insert into sp values('s4','p4',300);
	insert into sp values('s4','p5',400);
	
UPDATE `s` SET `s_status` = '10' WHERE `s`.`sno` = 's3';

CREATE table temp( pno char(3) primary key, pname varchar(20), color varchar(10), wight float(5.2), p_city varchar(25) );

alter table temp add pnum varchar(20) NOT NULL;

drop table temp;

*QUE-2*
=======
1)select DISTINCT * from p where P_CITY='London';
2)select DISTINCT pname,wight AS 'Maximum Weight' from p where wight = (select max(wight) from p); 
3)select DISTINCT pname,pno from p where color='red';
4)select DISTINCT s.sname,s.s_city from s join sp on s.sno=sp.sno where sp.qty>200; 
5)select DISTINCT max(wight) AS 'Second Highest Weight' from p where wight < (select max(wight) from p);

*QUE-3*
=======
6)select DISTINCT sp.sno,sp.qty from sp join p on sp.pno=p.pno where wight=(select max(wight) from p);
7)select DISTINCT s.sname,sp.qty from s,sp,p where s.sno=sp.sno AND p.pno=sp.pno AND color='red';
8)select DISTINCT s.sname,p.p_city,sp.qty from s,p,sp where s.sno=sp.sno AND p.pno=sp.pno AND s.s_status<30;
9)select sno,sum(qty) as 'Suppler Total Qty' from sp GROUP by sno;
10)SELECT pno,sum(qty) as 'Parts Total Qty' from sp GROUP by pno;

*QUE-4*
=======
11)SELECT p.pname as 'Parts Name',sum(sp.qty) as 'Parts Total Qty' from p,sp where p.pno=sp.pno GROUP by p.pno;
12)select s.sno,s.sname,s.s_status,s.s_city,sum(sp.qty) from s,sp where s.sno=sp.sno AND s.sno < 's4' GROUP by sno;
13)select s.sno,s.sname,s.s_status,s.s_city,sum(sp.qty) from s,sp where s.sno=sp.sno AND s.s_status=20 GROUP by sno;


*QUE-5*
=======
CREATE TABLE dept(dept_id int Primary key, dept_name varchar(30), dept_location VARCHAR(50));
INSERT INTO dept VALUES(1,'Computer','Ahemedabad');
INSERT INTO dept VALUES(2,'Micro Biology','Sadra');
INSERT INTO dept VALUES(3,'Management','Randheja');
INSERT INTO dept VALUES(4,'Main Office','Ahemedabad');

CREATE TABLE emp(emp_id int Primary key, emp_name varchar(30),emp_dept_id int,emp_boss_id int,emp_salary int,FOREIGN KEY(emp_dept_id) REFERENCES dept(dept_id));
INSERT INTO emp VALUES(101,'Nikhil',1,101,200000);
INSERT INTO emp VALUES(102,'Satish',1,101,2100000);
INSERT INTO emp VALUES(103,'Vrushali',1,101,175000);
INSERT INTO emp VALUES(201,'Archna',2,201,200000);
INSERT INTO emp VALUES(202,'Tanvi',2,201,135000);
INSERT INTO emp VALUES(203,'Dharti',2,201,175000);
INSERT INTO emp VALUES(301,'Hemali',3,301,235000);
INSERT INTO emp VALUES(302,'Vishal',3,301,180000);
INSERT INTO emp VALUES(303,'Nafis',3,302,199000);
INSERT INTO emp VALUES(401,'Namrata',4,401,500000);
INSERT INTO emp VALUES(402,'Bipin',4,401,450000);
INSERT INTO emp VALUES(403,'Narendra',4,402,1000000);
INSERT INTO emp VALUES(404,'Mohan',4,402,800000);

*QUE-6*
=======
1)select DISTINCT emp.emp_name as 'Employee Name',
	dept.dept_name as 'Employee Department',boss.emp_name as 'Boss Name',dept.dept_name 
	as 'Boss Department' 
	from emp,emp as boss,dept 
	where emp.emp_dept_id=dept.dept_id 
	AND emp.emp_boss_id=boss.emp_id;
	
2)select DISTINCT emp.emp_name as 'Employee Name',
	dept.dept_name as 'Employee Department',boss.emp_name as 'Boss Name',dept.dept_name 
	as 'Boss Department' 
	from emp,emp as boss,dept 
	where emp.emp_dept_id=dept.dept_id 
	AND emp.emp_boss_id=boss.emp_id
	AND emp.emp_salary > boss.emp_salary;
	
*QUE-7*
=======
3)select dept.dept_name,max(emp.emp_salary) as 'Maximum salary'
	from emp,dept 
	where emp.emp_dept_id=dept.dept_id
	group by emp.emp_dept_id;
	
4)select dept.dept_name,count(emp.emp_id) as 'Maximum salary'
	from emp,dept 
	where emp.emp_dept_id=dept.dept_id
	group by emp.emp_dept_id;
	
*QUE-8*
=======