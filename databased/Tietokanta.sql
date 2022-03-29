-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`asiakas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`asiakas` (
  `idasiakas` INT NOT NULL AUTO_INCREMENT,
  `nimi` VARCHAR(45) NOT NULL,
  `osoite` VARCHAR(45) NOT NULL,
  `puhelin` INT NOT NULL,
  PRIMARY KEY (`idasiakas`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`tili`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`tili` (
  `idtili` INT NOT NULL AUTO_INCREMENT,
  `saldo` INT NOT NULL,
  PRIMARY KEY (`idtili`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`kortti`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`kortti` (
  `idkortti` INT NOT NULL AUTO_INCREMENT,
  `pin` INT NOT NULL,
  `asiakas_idasiakas` INT NOT NULL,
  `tili_idtili` INT NOT NULL,
  PRIMARY KEY (`idkortti`, `asiakas_idasiakas`, `tili_idtili`),
  INDEX `fk_kortti_asiakas1_idx` (`asiakas_idasiakas` ASC) VISIBLE,
  INDEX `fk_kortti_tili1_idx` (`tili_idtili` ASC) VISIBLE,
  CONSTRAINT `fk_kortti_asiakas1`
    FOREIGN KEY (`asiakas_idasiakas`)
    REFERENCES `mydb`.`asiakas` (`idasiakas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_kortti_tili1`
    FOREIGN KEY (`tili_idtili`)
    REFERENCES `mydb`.`tili` (`idtili`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`tilitapahtumat`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`tilitapahtumat` (
  `idtilitapahtumat` INT NOT NULL AUTO_INCREMENT,
  `paiv/klo` DATETIME NOT NULL,
  `tapahtuma` VARCHAR(45) NOT NULL,
  `summa` VARCHAR(45) NOT NULL,
  `tili_idtili` INT NOT NULL,
  PRIMARY KEY (`idtilitapahtumat`, `tili_idtili`),
  INDEX `fk_tilitapahtumat_tili1_idx` (`tili_idtili` ASC) VISIBLE,
  CONSTRAINT `fk_tilitapahtumat_tili1`
    FOREIGN KEY (`tili_idtili`)
    REFERENCES `mydb`.`tili` (`idtili`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`tili_has_asiakas`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`tili_has_asiakas` (
  `tili_idtili` INT NOT NULL AUTO_INCREMENT,
  `asiakas_idasiakas` INT NOT NULL,
  PRIMARY KEY (`tili_idtili`, `asiakas_idasiakas`),
  INDEX `fk_tili_has_asiakas_asiakas1_idx` (`asiakas_idasiakas` ASC) VISIBLE,
  INDEX `fk_tili_has_asiakas_tili_idx` (`tili_idtili` ASC) VISIBLE,
  CONSTRAINT `fk_tili_has_asiakas_tili`
    FOREIGN KEY (`tili_idtili`)
    REFERENCES `mydb`.`tili` (`idtili`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_tili_has_asiakas_asiakas1`
    FOREIGN KEY (`asiakas_idasiakas`)
    REFERENCES `mydb`.`asiakas` (`idasiakas`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
