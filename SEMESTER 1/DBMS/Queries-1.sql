TABLE:S
*********

CREATE TABLE S(
    SNO CHAR(3) PRIMARY KEY,
    SNAME VARCHAR(50),
    S_STATUS INT,
    S_CITY VARCHAR
);
INSERT INTO S VALUES(
    's1',
    'Smith',
    20,
    'London'
);

INSERT INTO S VALUES(
    's2',
    'Jones',
    10,
    'Paris'
);

INSERT INTO S VALUES(
    's3',
    'Blake',
    10,
    'Paris'
);

INSERT INTO S VALUES(
    's4',
    'Clark',
    20,
    'London'
);

INSERT INTO S VALUES(
    's5',
    'Adams',
    30,
    'Athens'
);

TABLE:P
********
CREATE TABLE P(
    PNO CHAR(3) PRIMARY KEY,
    PNAME VARCHAR(20),
    COLOR VARCHAR(10),
    WEIGHT FLOAT(5.2),
    P_CITY VARCHAR(25)
);

INSERT INTO P VALUES(
    "p1",
    "Nut",
    "Red",
    12.0,
    'london'
);

INSERT INTO P VALUES(
    "p2",
    "Bolt",
    "Green",
    17.0,
    'Paris'
);

INSERT INTO P VALUES(
    "p3",
    "Screw",
    "Blue",
    17.0,
    'Oslo'
);

INSERT INTO P VALUES(
    "p4",
    "Screw",
    "Red",
    14.0,
    'london'
);

INSERT INTO P VALUES(
    "p5",
    "Cam",
    "Blue",
    12.0,
    'Paris'
);

INSERT INTO P VALUES(
    "p6",
    "Cg",
    "Red",
    19.0,
    'london'
);

TABLE:SP
**********
CREATE TABLE SP(
    SNO CHAR(3),
    PNO CHAR(3),
    QTY INT PRIMARY KEY(SNO, PNO),
    FOREIGN KEY(SNO) REFERENCES S(SNO),
    FOREIGN KEY(PNO) REFERENCES P(PNO)
);

INSERT INTO SP VALUES(
    's1',
    'p1',
    '300'
);

INSERT INTO SP VALUES(
    's1',
    'p2',
    '200'
);

INSERT INTO SP VALUES(
    's1',
    'p3',
    '400'
);

INSERT INTO SP VALUES(
    's1',
    'p4',
    '200'
);

INSERT INTO SP VALUES(
    's1',
    'p5',
    '100'
);

INSERT INTO SP VALUES(
    's1',
    'p6',
    '100'
);

INSERT INTO SP VALUES(
    's2',
    'p1',
    '300'
);

INSERT INTO SP VALUES(
    's2',
    'p2',
    '400'
);

INSERT INTO SP VALUES(
    's3',
    'p2',
    '200'
);

INSERT INTO SP VALUES(
    's4',
    'p2',
    '200'
);

INSERT INTO SP VALUES(
    's4',
    'p4',
    '300'
);

INSERT INTO SP VALUES(
    's4',
    'p5',
    '400'
);