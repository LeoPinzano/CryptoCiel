// RsaCiel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "RsaGestion.h"
#include "Hashgestion.h"
#include "AesGestion.h"

int main()
{
	HashGestion LM;
	std::string filename = "../DocReponses.txt";
	std::cout << LM.CalculateFileSHA256(filename) << std::endl;

	// Test AES
	AesGestion aesGestion;
	aesGestion.GenerateAESKey();
	aesGestion.SaveAESKeyToFile("../Keys/AES/key.txt");
	aesGestion.EncryptFileAES256(filename, "../DocChiffreAES.pem");
	aesGestion.DecryptFileAES256("../DocChiffreAES.pem", "../DocDechiffreAES.txt");

	// Test RSA
	RsaGestion rsaGestion;
	
	std::string message = "Un super message super chouette";
	rsaGestion.generationClef("../Keys/RSA/Public/publicKey.txt", "../Keys/RSA/Private/privateKey.txt", 2048);
	rsaGestion.dechiffrementRsa(rsaGestion.chiffrementRsa(message));
	
	/*
	rsaGestion.chargementClefs("../Keys/RSA/Public/publicKey.txt", "../Keys/RSA/Private/privateKey.txt");
	rsaGestion.chiffrementFichier(filename, "../DocChiffreRSA.pem", true);
	rsaGestion.dechiffreFichier(".. / DocChiffreRSA.pem");
	*/
}
