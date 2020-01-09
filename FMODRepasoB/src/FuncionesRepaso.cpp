#include "FuncionesRepaso.h"
#include <iostream>
#include<fmod_errors.h>

#include <chrono>

FuncionesRepaso::FuncionesRepaso()
{
}

FuncionesRepaso::~FuncionesRepaso()
{
}

//----------------------------------------------------------------
//INICIALIZADO Y CREACION DE LA CLASE ESTATICA SYSTEM
//----------------------------------------------------------------
//void FuncionesRepaso::fmod_init()
//{
//	FMOD::System_Create(&_system);
//	_result = _system->init(128, FMOD_INIT_NORMAL, 0);
//}
//
//void FuncionesRepaso::update()
//{
//	_result = _system->update();
//}
//
//void FuncionesRepaso::ERRCHECK(FMOD_RESULT result)
//{
//	if (_result != FMOD_OK) {
//		std::cout << FMOD_ErrorString(_result) << std::endl;
//	}
//}
//----------------------------------------------------------------

void FuncionesRepaso::createSound()
{
	FMOD::Sound* _sonido = nullptr;
	const char* _filename = "Sic Parvis Magna";

	_result = _system->createSound(_filename, FMOD_DEFAULT, 0, &_sonido);
	//para crear un stream utilizamos
	_result = _system->createStream(_filename, FMOD_DEFAULT, 0, &_sonido);
	// o también
	_result = _system->createSound(_filename, FMOD_CREATESTREAM, 0, &_sonido);
}
//otras posibilidades como FMOD_LOOP NORMAL, FMOD_3D ...

void FuncionesRepaso::playSound()
{
	FMOD::ChannelGroup* _channelGroup;
	const char* _channelName = "canal1";

	//creación del canal
	_result = _system->createChannelGroup(_channelName, &_channelGroup);

	FMOD::Sound* _sonido = nullptr;

	//si queremos añadir el sonido a un canal debemos pasar una referencia al grupo para poder metérsela al playsound
	_result = _system->playSound(_sonido, _channelGroup, true, &_channel);//asignacion de un canal al sonido ->true implica que el sonido empieza pausado
	//tenemos cargado el sonido y en pause
}

void FuncionesRepaso::stopSound()
{
	_result = _channel->stop();//libera el canal
}

void FuncionesRepaso::pauseResume()
{
	bool pause;
	_result = _channel->getPaused(&pause);
	pause = !pause;
	//pausamos o despausamos en funcion del estado anterior de pausa
	_result = _channel->setPaused(pause);
}

void FuncionesRepaso::setVolume(float vol)
{
	_result = _channel->setVolume(vol);
}

void FuncionesRepaso::startPlayingSoundAt(float time)
{
	_result = _channel->setPosition(time, FMOD_TIMEUNIT_MS);
}

void FuncionesRepaso::loopSound(int loop)
{
	//loop =
	// 0 una vez loop
	// n se reproduce n+1 veces
	_result = _channel->setLoopCount(loop);

	//repeticion infinita
	_result = _channel->setLoopCount(0);
}

void FuncionesRepaso::setPitch(float pitch)
{
	_result = _channel->setPitch(pitch);
}

void FuncionesRepaso::muteUnmute()
{
	bool mute;
	_result = _channel->getMute(&mute);
	mute = !mute;
	_result = _channel->setMute(mute);

}

void FuncionesRepaso::setPanorama(float panorama)
{
	_result = _channel->setPan(panorama);
}

void FuncionesRepaso::createChannel()
{
	FMOD::ChannelGroup* _channelGroupMaster;
	const char* _masterChannelName = "canalMaster";

	//creación del canal
	_result = _system->createChannelGroup(_masterChannelName, &_channelGroupMaster);


	FMOD::ChannelGroup* _channelGroup;
	const char* _channelName = "canal1";

	//creación del canal
	_result = _system->createChannelGroup(_channelName, &_channelGroup);
	//añadimos chanel grup como hijo de master
	_channelGroup->addGroup(_channelGroupMaster);

	//para obtener una referencia a la raiz
	FMOD::ChannelGroup* _canalMaestro;
	_result = _system->getMasterChannelGroup(&_canalMaestro); //almacenará en _canal maestro la referencia al padre o raiz del grupo _channelGroupMaster


	//trabajando sobre canales como sobre sonidos

	_canalMaestro->setPaused(true);
	_canalMaestro->setPitch(1.0f);
	// ... y así con el mresto de atributos
}

void FuncionesRepaso::trabajandoConTiempo()
{
	//variables tiempo
	std::chrono::steady_clock::time_point timePoint1;
	std::chrono::steady_clock::time_point timePoint2;

	timePoint1 = std::chrono::steady_clock::now();
	//diferencia temporal
	float diferenciaEnMilisegundos = std::chrono::duration_cast<std::chrono::milliseconds>(timePoint2 - timePoint1).count();

}


//----------------------------------------------------------------
//FMOD SONIDO EN 3D
//----------------------------------------------------------------

void FuncionesRepaso::setGlobalParameters()
{
	float rolloff = 1.0f;
	float doppler = 1.0f;
	float distanceScaler = 1.0f;

	_result = _system->set3DSettings(doppler, distanceScaler, rolloff);
}

void FuncionesRepaso::listenerInicialization()
{
	//x eje horizontal hacia la derecha
	//y eje vertical haci arriba
	//z eje profundidad hacia nosotros

	FMOD_VECTOR listenerPosition = { 0,0,0 };
	FMOD_VECTOR listenerVElocity = {/* x,y,z*/ 0,0,0};
	FMOD_VECTOR listenerUP = { 0,1,0 }; //Hacia donde apunta la cabeza del usuario -> en este caso estamos de pié en el plano x-z
	FMOD_VECTOR listenerAt = { 0,0,-1 }; // Como si estuviesemos mirando al frente, hacia la pantalla.

	_result = _system->set3DListenerAttributes(0, &listenerPosition, &listenerVElocity, &listenerAt, &listenerUP);
}

void FuncionesRepaso::createSource()
{
	FMOD::Sound* _soundSorce;
	const char* _sorceName = "VVV";
	_result = _system->createSound(_sorceName, FMOD_3D || FMOD_LOOP_NORMAL, 0, &_soundSorce);
}

void FuncionesRepaso::playSorce()
{
	FMOD::Channel* _channel;
	FMOD::Sound* _soundSorce = nullptr;
	int channelGrup = 0;
	_result = _system->playSound(_soundSorce, 0, true, &_channel);
}

void FuncionesRepaso::_setSorcePosition()
{

	FMOD_VECTOR _sorcePosition = {0,0,0};
	FMOD_VECTOR _sorceVelocity = {0,0,0};

	_result = _channel->set3DAttributes(&_sorcePosition, &_sorceVelocity);
}

void FuncionesRepaso::setConeDir()
{

	FMOD_VECTOR _coneDirection = { 1, 0,0 }; //cono orientado hacia la derecha
	_result = _sourceChannel->set3DConeOrientation(&_coneDirection);

}

void FuncionesRepaso::setConeAngles()
{
	float _interiorAngle = 30.0f;
	float _exteriorAngle = 60.0f;
	float _outsideVolume = 0.5f;//volumen fuera del ángulo exterior
	_sourceChannel->set3DConeSettings(_interiorAngle, _exteriorAngle, _outsideVolume);
}

void FuncionesRepaso::setAudibleAreas()
{
	FMOD::Channel* _sourceChannel = nullptr;
	//se define aquí el rango de actiación del rollOf
	float minDistance = 1.0f;
	float maxdistance = 100.0f;

	_result = _sourceChannel->set3DMinMaxDistance(minDistance, maxdistance);
}

//zonas de reverberación
void FuncionesRepaso::createReverb()
{
	FMOD::Reverb3D* _reverb = nullptr;
	_result = _system->createReverb3D(&_reverb);
}

void FuncionesRepaso::activeReverb()
{
	FMOD::Reverb3D* _reverb = nullptr;
	bool active;
	_result = _reverb->getActive(&active);
	active = !active;
	_result = _reverb->setActive(active);
}

void FuncionesRepaso::setReverbProperty()
{
	FMOD::Reverb3D* _reverb = nullptr;
	FMOD_REVERB_PROPERTIES _reverbProperty = FMOD_PRESET_CONCERTHALL;
	_result = _reverb->setProperties(&_reverbProperty);
}

void FuncionesRepaso::setReverbPositionAndDistances()
{
	FMOD::Reverb3D* _reverb = nullptr;
	FMOD_VECTOR _reverbPosition = {0,0,0};
	float maxDistance = 1.0f;
	float minDistance = 100.0f;
	_reverb->set3DAttributes(&_reverbPosition, minDistance, maxDistance);
}

void FuncionesRepaso::createGeometry()
{


	int numPoligons = 10;
	int maxVertices = 5;

	_result = _system->createGeometry(numPoligons, maxVertices, &_geometry);
}

void FuncionesRepaso::addPolygon()
{
	FMOD::Geometry* _myGeometry = nullptr;
	int poligonIndex = 0;
	float directOclusion = 1.0;
	float reverbOclusion = 1.0;
	bool doubleSided = true;
	int numVertices = 4;

	FMOD_VECTOR vA = { 0.0f,0.0f,0.0f };
	FMOD_VECTOR vB = { 0.0f,0.0f,0.0f };
	FMOD_VECTOR vC = { 0.0f,0.0f,0.0f };
	FMOD_VECTOR vD = { 0.0f,0.0f,0.0f };

	FMOD_VECTOR vertices[4];

	vertices[0] = vA;
	vertices[1] = vB;
	vertices[2] = vC;
	vertices[3] = vD;

	_result = _myGeometry->addPolygon(directOclusion, reverbOclusion, doubleSided, numVertices, vertices, &poligonIndex);
	
}

void FuncionesRepaso::setGeometryPosition()
{
	FMOD::Geometry* _myGeometry = nullptr;
	FMOD_VECTOR _geometryPosition;
	_result = _myGeometry->setPosition(&_geometryPosition);
}

void FuncionesRepaso::setGeometryRotation()
{
	FMOD::Geometry* _myGeometry = nullptr;
	FMOD_VECTOR _geometryUp = {0,1,0};
	FMOD_VECTOR _geometryForward = { 0,0,1 };
	_result = _myGeometry->setRotation(&_geometryForward, &_geometryUp);
}






