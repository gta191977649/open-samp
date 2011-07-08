#ifndef __CPLAYER_H__
#define __CPLAYER_H__

#define PLAYER_STATE_NONE			0
#define PLAYER_STATE_ONFOOT			1
#define PLAYER_STATE_DRIVER			2
#define PLAYER_STATE_PASSENGER		3
#define PLAYER_STATE_WASTED			7
#define PLAYER_STATE_SPAWNED		8
#define PLAYER_STATE_SPECTACTING	9


typedef struct SPAWNS_t // size 0x2E
{
#pragma pack( 1 )
	uint8_t		Team;
	int			Skin;
	uint8_t		unk;
	float		posX;
	float		posY;
	float		posZ;
	float		zAngle;
	int			weapons[ 3 ];
	int			ammo[ 3 ];
} tSPAWNS;


typedef struct AttachedObject_t // size 0x2C
{
#pragma pack( 1 )
	uint32_t	modelID;
	uint32_t	boneID;
	tVector		offset;
	tVector		rotation;
	tVector		scale;
} tAttachedObject;



typedef struct ON_FOOT_SYNC_t // size 0x44
{
#pragma pack( 1 )
	uint16_t	leftRightKeysOnfoot;					// + 0x0000
	uint16_t	updownKeysOnfoot;						// + 0x0002
	uint16_t	keysOnfoot;								// + 0x0004
	tVector		position;								// + 0x0006 -> 0x000E
	float		zAngle;									// + 0x0012

	uint8_t		unknown0016[0x22-0x16];					// + 0x0016

	uint8_t		health;									// + 0x0022		Chelou d'utiliser des uint8_t au lieu de float mais bon Kye, c'est Kye
	uint8_t		armour;									// + 0x0023
	uint8_t		weapon;									// + 0x0024
	uint8_t		specialAction;							// + 0x0025
	tVector		velocity;								// + 0x0026

	uint8_t		unknown0032[0x3E-0x32];					// + 0x0032


	uint16_t	surfingVehicleID;						// + 0x003E	
	uint16_t	animationIndex;							// + 0x0040

	uint16_t	unknown0042;


} ON_FOOT_SYNC;


class CPlayer // size 0x1AF8
{
#pragma pack( 1 )
public:

	tVector		position;								// + 0x000	- 0x08
	float		health;									// + 0x000C - 12
	float		armour;									// + 0x0010	- 16
	uint32_t	unknown0014;							// + 0x0014	- 20
	uint32_t	unknown0018;							// + 0x0018	- 24
	uint32_t	unknown001C;							// + 0x001C	- 28
	uint32_t	unknown0020;							// + 0x0020 - 32
	float		facingAngle;							// + 0x0024 - 36
	BOOL		allowedToTeleport;						// + 0x0028 - 40
	tVector		velocity;								// + 0x002C - 44
	void*		playerText3DLabels;						// + 0x0038 - 56
	uint16_t	myPlayerID;								// + 0x003C - 60
	uint32_t	unknown003E;							// + 0x003E - 62

	ON_FOOT_SYNC onFootSyncData;						// + 0x0042

	uint8_t		unknown0086[0x8C-0x86];					// + 0x0084
	uint16_t	leftRightKeysOnVehicle;					// + 0x008C
	uint16_t	updownKeysOnVehicle;					// + 0x008A
	uint16_t	keysOnVehicle;							// + 0x0088

	uint8_t		unknown008A[0xDE-0x8A];					// + 0x008A

	tVector		cameraFrontVector;						// + 0x00DE	- 0xE6
	tVector		cameraPosition;							// + 0x00EA - 0xF2

	uint8_t		unknown00F6[0xFA-0xF6];					// + 0x00F6

	uint8_t		weaponState;							// + 0x00FA - 250

	uint16_t	leftRightKeysOnSpectating;				// + 0x00FC
	uint16_t	updownKeysOnSpectating;					// + 0x00FE
	uint16_t	keysOnSpectating;						// + 0x0100

	uint8_t		unknown0102[0x183-0x102];				// + 0x0102

//	uint8_t		unknown0183[5][44];						// + 0x0183 -> 0x025F
	tAttachedObject	attachedObject[5];					// + 0x0183 -> 0x025F
	BOOL		attachedObjectSlot[5];					// + 0x025F -> 0x273

	uint16_t	unknown0273;							// + 0x0273
	uint32_t	unknown0275;							// + 0x0275
	uint32_t	unknown0279;							// + 0x0279

	uint8_t		unknown027D[0x281-0x27D];				// + 0x027D						

	uint8_t		playerState;							// + 0x0281	- 641
	tVector		checkpointPosition;						// + 0x0282 - 0x28A
	float		checkpointSize;							// + 0x028E
	BOOL		isInCheckpoint;							// + 0x0292
	tVector		raceCheckpointPos;						// + 0x0296 - 0x29E
	tVector		nextraceCheckpointPos;					// + 0x02A2 - 2AA
	uint8_t		raceCheckpointType;						// + 0x02AE
	float		raceCheckpointSize;						// + 0x02AF
	BOOL		isInRaceCheckpoint;						// + 0x02B3

	uint32_t	unknown02B7;							// + 0x02B7
	bool		bisPlayerStreamedIn[MAX_PLAYERS];		// + 0x02BB
	bool		bisVehicleStreamedIn[MAX_VEHICLES];		// + 0x04AF
	uint8_t		unknown0C7F[400];						// + 0x0C7F
	uint8_t		bisText3DLabelStreamedIn[MAX_TEXT_LABELS];// + 0x0E0F
	uint8_t		unknown120F[2048];						// + 0x120F

	uint32_t	unknown1A0F;							// + 0x1A0F
	uint32_t	unknown1A13;							// + 0x1A13
	uint32_t	unknown1A17;							// + 0x1A17
	uint32_t	Text3DLabelsNumber;						// + 0x1A1B

	uint8_t		unknown1A1F[0x1A23-0x1A1F];				// + 0x1A1F

	uint32_t	unknown1A23;							// + 0x1A23
	uint32_t	unknown1A27;							// + 0x1A27

	uint16_t	skillsLevel[11];						// + 0x1A37 -> 0x1A4D
	uint32_t	unknown1A4D;							// + 0x1A4D


	tSPAWNS		customSpawn;							// + 0x1A51

	BOOL		hasCustomSpawn;							// + 0x1A7F
	uint8_t		wantedLevel;							// + 0x1A83 - 6787
	uint8_t		fightingStyle;							// + 0x1A84	- 6788
	uint8_t		currentSeatinVehicle;					// + 0x1A85
	uint16_t	currentVehicleID;						// + 0x1A86	- 6790
	uint32_t	nickNameColor;							// + 0x1A88
	BOOL		bshowCheckpoint;						// + 0x1A8C
	BOOL		bshowRaceCheckpoint;					// + 0x1A90
	uint32_t	currentInterior;						// + 0x1A94	- 6804
	uint16_t	ammoInSlot[ 13 ];						// + 0x1A98	- 6808

	uint8_t		unknown1AB2[0x1ACC-0x1AB2];				// + 0x1AB2

	uint8_t		weaponInSlot[ 13 ];						// + 0x1ACC	- 6860
	uint8_t		currentWeapon;							// + 0x1AD9
	uint8_t		time;									// + 0x1ADA
	float		gameTime;								// + 0x1ADB
	uint8_t		spectateType;							// + 0x1ADF	- 6879
	uint32_t	spectateID;								// + 0x1AE0
	uint32_t	unknown1AE4;							// + 0x1AE4
	uint32_t	NPCRecordingType;						// + 0x1AE8				http://wiki.sa-mp.com/wiki/Recordingtypes
	FILE*		ioFileNPC;								// + 0x1AEC
	uint32_t	lastNPCWritingInFile;					// + 0x1AF0	

	void*		playerVarsClass;						// + 0x1AF4


	int stopNPCRecordingData( );
	int startNPCRecordingData( int recordType, char* recordname );


	void createText3DLabel( uint16_t labelID );
	void destroyText3DLabel( uint16_t labelID );

	float GetDistanceFrom3DPoint( tVector point );
	float GetDistanceFrom3DPoint( float x, float y, float z );

	bool isPlayerStreamedIn( _PlayerID playerID );
	bool isVehicleStreamedIn( uint16_t vehicleID );

	void setRaceCheckpoint( uint8_t type, tVector position, tVector next_position, float size );
	void showRaceCheckpoint( bool show );

	void setCheckpoint( tVector position, float size );
	void showCheckpoint( bool show );


	uint16_t getCurrentVehicleID( );

	tVector* getCameraPosition( );
	tVector* getCameraFrontVector( );
	tVector* getPosition( );

	float getFacingAngle( );
	uint8_t getState( );

	

	float getHealth( );


	CPlayer( );
	~CPlayer( );
private:


};




#endif