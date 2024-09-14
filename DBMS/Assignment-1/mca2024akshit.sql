-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 03, 2024 at 03:36 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.0.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `mca2024akshit`
--

-- --------------------------------------------------------

--
-- Table structure for table `dept`
--

CREATE TABLE `dept` (
  `dept_id` int(11) NOT NULL,
  `dept_name` varchar(30) DEFAULT NULL,
  `dept_location` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `dept`
--

INSERT INTO `dept` (`dept_id`, `dept_name`, `dept_location`) VALUES
(1, 'Computer', 'Ahemedabad'),
(2, 'Micro Biology', 'Sadra'),
(3, 'Management', 'Randheja'),
(4, 'Main Office', 'Ahemedabad');

-- --------------------------------------------------------

--
-- Table structure for table `emp`
--

CREATE TABLE `emp` (
  `emp_id` int(11) NOT NULL,
  `emp_name` varchar(30) DEFAULT NULL,
  `emp_dept_id` int(11) DEFAULT NULL,
  `emp_boss_id` int(11) DEFAULT NULL,
  `emp_salary` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `emp`
--

INSERT INTO `emp` (`emp_id`, `emp_name`, `emp_dept_id`, `emp_boss_id`, `emp_salary`) VALUES
(101, 'Nikhil', 1, 101, 200000),
(102, 'Satish', 1, 101, 2100000),
(103, 'Vrushali', 1, 101, 175000),
(201, 'Archna', 2, 201, 200000),
(202, 'Tanvi', 2, 201, 135000),
(203, 'Dharti', 2, 201, 175000),
(301, 'Hemali', 3, 301, 235000),
(302, 'Vishal', 3, 301, 180000),
(303, 'Nafis', 3, 302, 199000),
(401, 'Namrata', 4, 401, 500000),
(402, 'Bipin', 4, 401, 450000),
(403, 'Narendra', 4, 402, 1000000),
(404, 'Mohan', 4, 402, 800000);

-- --------------------------------------------------------

--
-- Table structure for table `p`
--

CREATE TABLE `p` (
  `pno` char(3) NOT NULL,
  `pname` varchar(20) DEFAULT NULL,
  `color` varchar(10) DEFAULT NULL,
  `wight` float DEFAULT NULL,
  `p_city` varchar(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `p`
--

INSERT INTO `p` (`pno`, `pname`, `color`, `wight`, `p_city`) VALUES
('p1', 'Nut', 'Red', 12, 'London'),
('p2', 'Bolt', 'Green', 17, 'Paris'),
('p3', 'Screw', 'Blue', 17, 'Oslo'),
('p4', 'Screw', 'Red', 14, 'London'),
('p5', 'Cam', 'Blue', 12, 'Paris'),
('p6', 'Cg', 'Red', 19, 'London');

-- --------------------------------------------------------

--
-- Table structure for table `s`
--

CREATE TABLE `s` (
  `sno` char(3) NOT NULL,
  `sname` varchar(50) DEFAULT NULL,
  `s_status` int(11) DEFAULT NULL,
  `s_city` varchar(25) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `s`
--

INSERT INTO `s` (`sno`, `sname`, `s_status`, `s_city`) VALUES
('s1', 'Smith', 20, 'London'),
('s2', 'Jones', 10, 'Paris'),
('s3', 'Blake', 10, 'Paris'),
('s4', 'Clark', 20, 'London'),
('s5', 'Adams', 30, 'Athens');

-- --------------------------------------------------------

--
-- Table structure for table `sp`
--

CREATE TABLE `sp` (
  `sno` char(30) NOT NULL,
  `pno` char(3) NOT NULL,
  `qty` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `sp`
--

INSERT INTO `sp` (`sno`, `pno`, `qty`) VALUES
('s1', 'p1', 300),
('s1', 'p2', 200),
('s1', 'p3', 400),
('s1', 'p4', 200),
('s1', 'p5', 100),
('s1', 'p6', 100),
('s2', 'p1', 300),
('s2', 'p2', 400),
('s3', 'p2', 200),
('s4', 'p2', 200),
('s4', 'p4', 300),
('s4', 'p5', 400);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `dept`
--
ALTER TABLE `dept`
  ADD PRIMARY KEY (`dept_id`);

--
-- Indexes for table `emp`
--
ALTER TABLE `emp`
  ADD PRIMARY KEY (`emp_id`),
  ADD KEY `emp_dept_id` (`emp_dept_id`);

--
-- Indexes for table `p`
--
ALTER TABLE `p`
  ADD PRIMARY KEY (`pno`);

--
-- Indexes for table `s`
--
ALTER TABLE `s`
  ADD PRIMARY KEY (`sno`);

--
-- Indexes for table `sp`
--
ALTER TABLE `sp`
  ADD PRIMARY KEY (`sno`,`pno`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `emp`
--
ALTER TABLE `emp`
  ADD CONSTRAINT `emp_ibfk_1` FOREIGN KEY (`emp_dept_id`) REFERENCES `dept` (`dept_id`);

--
-- Constraints for table `sp`
--
ALTER TABLE `sp`
  ADD CONSTRAINT `sp_ibfk_1` FOREIGN KEY (`sno`) REFERENCES `s` (`sno`),
  ADD CONSTRAINT `sp_ibfk_2` FOREIGN KEY (`pno`) REFERENCES `p` (`pno`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
