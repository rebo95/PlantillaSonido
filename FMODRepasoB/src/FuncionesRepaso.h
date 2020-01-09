#pragma once

#include <fmod.hpp>
class FuncionesRepaso {

private:
	//----------------------------------------------------------------
	//INICIALIZADO Y CREACION DE LA CLASE ESTATICA SYSTEM
	//----------------------------------------------------------------
	//static FMOD::System* _system;
	//static FMOD_RESULT _result;
	//----------------------------------------------------------------

	FMOD::System* _system;
	FMOD::Channel* _channel;
	FMOD_RESULT _result;

	FMOD::Channel* _sourceChannel;
	FMOD::Geometry* _geometry;

public:
	FuncionesRepaso();
	~FuncionesRepaso();


	//static void fmod_init();
	//static void ERRCHECK(FMOD_RESULT result);
	//static void update();
	//----------------------------------------------------------------
	//SONIDO Y CARGA DE SONIDO 2D
	//----------------------------------------------------------------
	void createSound();
	void playSound();
	void stopSound();
	void pauseResume();
	void setVolume(float vol);
	void startPlayingSoundAt(float time);
	void loopSound(int loop);

	void setPitch(float pitch);
	void muteUnmute();
	void setPanorama(float panorama);

	//----------------------------------------------------------------
	//Canales
	//----------------------------------------------------------------
	void createChannel();

	//----------------------------------------------------------------
	//Variables de tiempo
	//----------------------------------------------------------------
	void trabajandoConTiempo();



	//----------------------------------------------------------------
	//FMOD SONIDO EN 3D
	//----------------------------------------------------------------

	void setGlobalParameters();
	//----------------------------------------------------------------
	//El listener
	void listenerInicialization();

	//Source
	void createSource();
	void playSorce();

	//posicionamiento de la fuente
	void _setSorcePosition();
	//el resto de modificaciones sobre el canal son equivalentes a las del sonido 2D

	//direccionalidad de las fuentes
	void setConeDir();
	void setConeAngles();

	//rangos de audición de las fuentes
	void setAudibleAreas();

	//reverb
	void createReverb();
	void activeReverb();
	void setReverbProperty();
	void setReverbPositionAndDistances();

	//Creación De polígonos
	void createGeometry();
	void addPolygon();
	void setGeometryPosition();
	void setGeometryRotation();


};
