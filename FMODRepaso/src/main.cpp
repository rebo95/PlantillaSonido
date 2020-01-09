
#include<fmod.hpp>
#include<fmod_errors.h>
#include<conio.h>
#include<iostream>
#include<fmod_studio.hpp>


void ERRCHECK(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		std::cout << FMOD_ErrorString(result) << std::endl;
		exit(-1);
	}
}
FMOD_RESULT result = FMOD_RESULT::FMOD_OK;

int main() {

	//FMOD::Studio::System* _studioSystem = NULL;
	//FMOD::Studio::System::create(&_studioSystem);

	//ERRCHECK(_studioSystem->initialize(1024, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, 0));

	//FMOD::Studio::Bank* masterBank = NULL;
	//ERRCHECK(_studioSystem->loadBankFile("res/MasterBank.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &masterBank));

	//FMOD::Studio::Bank* stringsBank = NULL;
	//ERRCHECK(_studioSystem->loadBankFile("res/MasterBank.strings.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &stringsBank));

	//FMOD::Studio::Bank* stepsBank = NULL;
	//ERRCHECK(_studioSystem->loadBankFile("res/StepsBank.bank", FMOD_STUDIO_LOAD_BANK_NORMAL, &stepsBank));

	//// Get the Looping Ambience event
	//FMOD::Studio::EventDescription* pasos = NULL;
	//ERRCHECK(_studioSystem->getEvent("event:/Steps", &pasos));

	//FMOD::Studio::EventInstance* pasosInstance = NULL;
	//ERRCHECK(pasos->createInstance(&pasosInstance));

	//ERRCHECK(pasosInstance->start());

	//ERRCHECK(pasosInstance->setParameterByName("velocidad", 0.1));

	//do
	//{
	//	_studioSystem->update();
	//} while (true);

	//---------- Inicialización de System ----------//
// Creamos System
	FMOD::System* FMODSystem;
	result = FMOD::System_Create(&FMODSystem);
	ERRCHECK(result);
	// Inicializamos System
	result = FMODSystem->init(128, FMOD_INIT_NORMAL, nullptr);
	ERRCHECK(result);
	// Inicializamos el motor de audio 3D
	result = FMODSystem->set3DSettings(1.0f, 1.0f, 1.0f);
	ERRCHECK(result);


	bool running = true;
	
	while (running)
	{

		if (_kbhit()) {

			system("CLS");

			int key = _getch();
		}

		FMODSystem->update();
	}

	FMODSystem->release();

	return 0;
}