USE exile;

DROP TABLE IF EXISTS `raid_message_history`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `raid_message_history` (
  `message_id` int NOT NULL AUTO_INCREMENT,
  `flag_stolen_by_uid` varchar(45) DEFAULT NULL,
  `raidmessage` text,
  `territory_id` int DEFAULT NULL,
  `territory_owner_uid` varchar(45) DEFAULT NULL,
  `message_time` datetime DEFAULT NULL,
  PRIMARY KEY (`message_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;