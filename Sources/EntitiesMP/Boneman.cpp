/*
 * This file is generated by Entity Class Compiler, (c) CroTeam 1997-98
 */

#line 4 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"

#include "StdH.h"
#include "Models/Enemies/Boneman/Boneman.h"

#include <EntitiesMP/Boneman.h>
#include <EntitiesMP/Boneman_tables.h>
#line 11 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"

// info structure
static EntityInfo eiBoneman = {
 EIBT_BONES, 250.0f,
 0.0f, 1.9f, 0.0f,    // source (eyes)
 0.0f, 1.9f, 0.0f,    // target (body)
};

#define BONES_HIT 2.8f
#define FIRE_RIGHT_HAND     FLOAT3D( 0.25f, 1.5f, 0.0f)
#define FIRE_LEFT_HAND      FLOAT3D(-0.25f, 1.5f, 0.0f)

void CBoneman::SetDefaultProperties(void) {
  m_bFistHit = FALSE ;
  m_bTouchAnother = FALSE ;
  m_soFeet.SetOwner(this);
m_soFeet.Stop_internal();
  m_bRunSoundPlaying = FALSE ;
  CEnemyBase::SetDefaultProperties();
}
  
#line 57 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::Precache(void) {
#line 58 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
CEnemyBase  :: Precache  ();
#line 59 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheSound  (SOUND_IDLE );
#line 60 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheSound  (SOUND_SIGHT );
#line 61 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheSound  (SOUND_WOUND );
#line 62 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheSound  (SOUND_FIRE );
#line 63 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheSound  (SOUND_KICK );
#line 64 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheSound  (SOUND_PUNCH );
#line 65 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheSound  (SOUND_DEATH );
#line 66 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheSound  (SOUND_RUN );
#line 68 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheModel  (MODEL_BONEMAN_BODY );
#line 69 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheModel  (MODEL_BONEMAN_HAND );
#line 70 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheModel  (MODEL_BONEMAN_LEGS );
#line 72 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PrecacheClass  (CLASS_PROJECTILE  , PRT_BONEMAN_FIRE );
#line 73 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  CTString CBoneman::GetPlayerKillDescription(const CTString & strPlayerName,const EDeath & eDeath) 
#line 77 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
{
#line 78 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
CTString str ;
#line 79 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(eDeath  . eLastDamage  . dmtType  == DMT_CLOSERANGE ){
#line 80 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
str  . PrintF  (TRANS  ("%s was ripped apart by a Kleer") , strPlayerName );
#line 81 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}else {
#line 82 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
str  . PrintF  (TRANS  ("%s was killed by a Kleer") , strPlayerName );
#line 83 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 84 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return str ;
#line 85 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  const CTFileName & CBoneman::GetComputerMessageName(void)const {
#line 88 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
static DECLARE_CTFILENAME  (fnm  , "Data\\Messages\\Enemies\\Boneman.txt");
#line 89 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return fnm ;
#line 90 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 93 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void * CBoneman::GetEntityInfo(void) {
#line 94 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return & eiBoneman ;
#line 95 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 98 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::ReceiveDamage(CEntity * penInflictor,enum DamageType dmtType,
#line 99 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT fDamageAmmount,const FLOAT3D & vHitPoint,const FLOAT3D & vDirection) 
#line 100 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
{
#line 102 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(! IsOfClass  (penInflictor  , "Boneman")){
#line 103 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
CEnemyBase  :: ReceiveDamage  (penInflictor  , dmtType  , fDamageAmmount  , vHitPoint  , vDirection );
#line 104 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 105 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 107 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::LeaveStain(BOOL bGrow) 
#line 108 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
{
#line 110 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 113 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
INDEX CBoneman::AnimForDamage(FLOAT fDamage) {
#line 114 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
INDEX iAnim ;
#line 115 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
switch(IRnd  () % 5){
#line 116 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
case 0: iAnim  = BONEMAN_ANIM_WOUNDCRITICAL01 ;break ;
#line 117 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
case 1: iAnim  = BONEMAN_ANIM_WOUNDCRITICAL02 ;break ;
#line 118 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
case 2: iAnim  = BONEMAN_ANIM_WOUNDCRITICAL03 ;break ;
#line 119 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
case 3: iAnim  = BONEMAN_ANIM_FALL01 ;break ;
#line 120 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
case 4: iAnim  = BONEMAN_ANIM_FALL02 ;break ;
#line 121 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
default  : ASSERTALWAYS  ("Boneman unknown damage");
#line 122 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 123 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StartModelAnim  (iAnim  , 0);
#line 124 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
DeactivateRunningSound  ();
#line 125 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return iAnim ;
#line 126 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 129 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
INDEX CBoneman::AnimForDeath(void) {
#line 130 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
INDEX iAnim ;
#line 131 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
switch(IRnd  () % 2){
#line 132 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
case 0: iAnim  = BONEMAN_ANIM_DEATHTOBACK ;break ;
#line 133 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
case 1: iAnim  = BONEMAN_ANIM_DEATHTOFRONT ;break ;
#line 134 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
default  : ASSERTALWAYS  ("Boneman unknown death");
#line 135 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 136 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StartModelAnim  (iAnim  , 0);
#line 137 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
DeactivateRunningSound  ();
#line 138 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return iAnim ;
#line 139 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 141 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT CBoneman::WaitForDust(FLOAT3D & vStretch) {
#line 142 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(GetModelObject  () -> GetAnim  () == BONEMAN_ANIM_DEATHTOBACK )
#line 143 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
{
#line 144 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 1.0f;
#line 145 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return 0.48f;
#line 146 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 147 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
else if(GetModelObject  () -> GetAnim  () == BONEMAN_ANIM_DEATHTOFRONT )
#line 148 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
{
#line 149 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vStretch  = FLOAT3D (1 , 1 , 2) * 0.75f;
#line 150 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return 0.48f;
#line 151 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 152 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return - 1.0f;
#line 153 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 155 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::DeathNotify(void) {
#line 156 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
ChangeCollisionBoxIndexWhenPossible  (BONEMAN_COLLISION_BOX_DEATH );
#line 157 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 160 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::StandingAnim(void) {
#line 161 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StartModelAnim  (BONEMAN_ANIM_STANDLOOP  , AOF_LOOPING  | AOF_NORESTART );
#line 162 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
DeactivateRunningSound  ();
#line 163 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 164 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::WalkingAnim(void) {
#line 165 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StartModelAnim  (BONEMAN_ANIM_WALKLOOP  , AOF_LOOPING  | AOF_NORESTART );
#line 166 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
DeactivateRunningSound  ();
#line 167 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 168 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::RunningAnim(void) {
#line 169 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StartModelAnim  (BONEMAN_ANIM_RUNLOOP  , AOF_LOOPING  | AOF_NORESTART );
#line 170 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
ActivateRunningSound  ();
#line 171 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 172 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::RotatingAnim(void) {
#line 173 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StartModelAnim  (BONEMAN_ANIM_WALKLOOP  , AOF_LOOPING  | AOF_NORESTART );
#line 174 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
DeactivateRunningSound  ();
#line 175 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 178 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::IdleSound(void) {
#line 179 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soSound  , SOUND_IDLE  , SOF_3D );
#line 180 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 181 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::SightSound(void) {
#line 182 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soSound  , SOUND_SIGHT  , SOF_3D );
#line 183 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 184 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::WoundSound(void) {
#line 185 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soSound  , SOUND_WOUND  , SOF_3D );
#line 186 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 187 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::DeathSound(void) {
#line 188 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soSound  , SOUND_DEATH  , SOF_3D );
#line 189 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 193 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::ActivateRunningSound(void) 
#line 194 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
{
#line 195 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(! m_bRunSoundPlaying ){
#line 196 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soFeet  , SOUND_RUN  , SOF_3D  | SOF_LOOP );
#line 197 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_bRunSoundPlaying  = TRUE ;
#line 198 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 199 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 200 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::DeactivateRunningSound(void) 
#line 201 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
{
#line 202 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_soFeet  . Stop  ();
#line 203 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_bRunSoundPlaying  = FALSE ;
#line 204 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
  
#line 210 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
void CBoneman::BlowUp(void) {
#line 212 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOATaabbox3D box ;
#line 213 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
GetBoundingBox  (box );
#line 214 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT fEntitySize  = box  . Size  () . MaxNorm  ();
#line 216 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D vNormalizedDamage  = m_vDamage  - m_vDamage  * (m_fBlowUpAmount  / m_vDamage  . Length  ());
#line 217 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vNormalizedDamage  /= Sqrt  (vNormalizedDamage  . Length  ());
#line 219 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vNormalizedDamage  *= 0.75f;
#line 221 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D vBodySpeed  = en_vCurrentTranslationAbsolute  - en_vGravityDir  * (en_vGravityDir  % en_vCurrentTranslationAbsolute );
#line 224 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Debris_Begin  (EIBT_BONES  , DPT_NONE  , BET_NONE  , fEntitySize  , vNormalizedDamage  , vBodySpeed  , 5.0f , 2.0f);
#line 226 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Debris_Spawn  (this  , this  , MODEL_BONEMAN_BODY  , TEXTURE_BONEMAN  , 0 , 0 , 0 , 0 , 0.0f , 
#line 227 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D (FRnd  () * 0.6f + 0.2f , FRnd  () * 0.6f + 0.2f , FRnd  () * 0.6f + 0.2f));
#line 228 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Debris_Spawn  (this  , this  , MODEL_BONEMAN_HAND  , TEXTURE_BONEMAN  , 0 , 0 , 0 , 0 , 0.0f , 
#line 229 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D (FRnd  () * 0.6f + 0.2f , FRnd  () * 0.6f + 0.2f , FRnd  () * 0.6f + 0.2f));
#line 230 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Debris_Spawn  (this  , this  , MODEL_BONEMAN_HAND  , TEXTURE_BONEMAN  , 0 , 0 , 0 , 0 , 0.0f , 
#line 231 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D (FRnd  () * 0.6f + 0.2f , FRnd  () * 0.6f + 0.2f , FRnd  () * 0.6f + 0.2f));
#line 232 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Debris_Spawn  (this  , this  , MODEL_BONEMAN_LEGS  , TEXTURE_BONEMAN  , 0 , 0 , 0 , 0 , 0.0f , 
#line 233 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D (FRnd  () * 0.6f + 0.2f , FRnd  () * 0.6f + 0.2f , FRnd  () * 0.6f + 0.2f));
#line 236 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SwitchToEditorModel  ();
#line 237 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetPhysicsFlags  (EPF_MODEL_IMMATERIAL );
#line 238 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetCollisionFlags  (ECF_IMMATERIAL );
#line 239 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
BOOL CBoneman::
#line 249 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Fire(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBoneman_Fire
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBoneman::Fire expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 251 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StartModelAnim  (BONEMAN_ANIM_ATTACKCLOSELOOP  , 0);
#line 252 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
DeactivateRunningSound  ();
#line 253 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetTimerAfter(0.35f);
Jump(STATE_CURRENT, 0x01310001, FALSE, EBegin());return TRUE;}BOOL CBoneman::H0x01310001_Fire_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310001
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01310002, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBoneman::H0x01310002_Fire_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310002
;
#line 254 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
ShootProjectile  (PRT_BONEMAN_FIRE  , FIRE_RIGHT_HAND  , ANGLE3D (0 , 0 , 0));
#line 255 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soSound  , SOUND_FIRE  , SOF_3D );
#line 256 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetTimerAfter(0.45f);
Jump(STATE_CURRENT, 0x01310003, FALSE, EBegin());return TRUE;}BOOL CBoneman::H0x01310003_Fire_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310003
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01310004, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBoneman::H0x01310004_Fire_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310004
;
#line 257 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
ShootProjectile  (PRT_BONEMAN_FIRE  , FIRE_LEFT_HAND  , ANGLE3D (0 , 0 , 0));
#line 258 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soSound  , SOUND_FIRE  , SOF_3D );
#line 259 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetTimerAfter(FRnd  () / 3 + 0.6f);
Jump(STATE_CURRENT, 0x01310005, FALSE, EBegin());return TRUE;}BOOL CBoneman::H0x01310005_Fire_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310005
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01310006, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBoneman::H0x01310006_Fire_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310006
;
#line 261 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Return(STATE_CURRENT,EReturn  ());
#line 261 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBoneman::
#line 264 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Hit(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBoneman_Hit
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBoneman::Hit expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 266 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(CalcDist  (m_penEnemy ) < BONES_HIT ){
#line 267 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Jump(STATE_CURRENT, STATE_CBoneman_HitWithBones, TRUE, EVoid());return TRUE;
#line 270 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}else if(CalcDist  (m_penEnemy ) < 10.0f){
#line 271 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Jump(STATE_CURRENT, STATE_CBoneman_JumpOnEnemy, TRUE, EVoid());return TRUE;
#line 272 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 275 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fShootTime  = _pTimer  -> CurrentTick  () + 0.5f;
#line 276 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Return(STATE_CURRENT,EReturn  ());
#line 276 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBoneman::
#line 280 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
JumpOnEnemy(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBoneman_JumpOnEnemy
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBoneman::JumpOnEnemy expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 281 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StartModelAnim  (BONEMAN_ANIM_ATTACKFAR  , 0);
#line 282 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
DeactivateRunningSound  ();
#line 285 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D vDir  = (m_penEnemy  -> GetPlacement  () . pl_PositionVector  - 
#line 286 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
GetPlacement  () . pl_PositionVector ) . Normalize  ();
#line 287 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vDir  *= ! GetRotationMatrix  ();
#line 288 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vDir  *= m_fCloseRunSpeed  * 1.5f;
#line 289 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vDir  (2) = 2.5f;
#line 290 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetDesiredTranslation  (vDir );
#line 291 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soSound  , SOUND_KICK  , SOF_3D );
#line 294 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SpawnReminder  (this  , 0.5f , 0);
#line 295 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_iChargeHitAnimation  = BONEMAN_ANIM_ATTACKFAR ;
#line 296 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fChargeHitDamage  = 20.0f;
#line 297 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fChargeHitAngle  = 0.0f;
#line 298 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fChargeHitSpeed  = 15.0f;
#line 299 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
STATE_CEnemyBase_ChargeHitEnemy, FALSE;
Jump(STATE_CURRENT, 0x01310009, FALSE, EBegin());return TRUE;}BOOL CBoneman::H0x01310009_JumpOnEnemy_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310009
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: Call(STATE_CURRENT, STATE_CEnemyBase_ChargeHitEnemy, FALSE, EVoid());return TRUE;case EVENTCODE_EReturn: Jump(STATE_CURRENT,0x0131000a, FALSE, __eeInput); return TRUE;default: return FALSE; }}BOOL CBoneman::H0x0131000a_JumpOnEnemy_02(const CEntityEvent &__eeInput){
#undef STATE_CURRENT
#define STATE_CURRENT 0x0131000a
const EReturn&__e= (EReturn&)__eeInput;
;
#line 300 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetTimerAfter(0.3f);
Jump(STATE_CURRENT, 0x0131000b, FALSE, EBegin());return TRUE;}BOOL CBoneman::H0x0131000b_JumpOnEnemy_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0131000b
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0131000c, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBoneman::H0x0131000c_JumpOnEnemy_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0131000c
;
#line 301 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Return(STATE_CURRENT,EReturn  ());
#line 301 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBoneman::
#line 305 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
HitWithBones(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBoneman_HitWithBones
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBoneman::HitWithBones expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 307 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StartModelAnim  (BONEMAN_ANIM_ATTACKCLOSELOOP  , 0);
#line 308 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
DeactivateRunningSound  ();
#line 311 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_bFistHit  = FALSE ;
#line 312 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetTimerAfter(0.35f);
Jump(STATE_CURRENT, 0x0131000e, FALSE, EBegin());return TRUE;}BOOL CBoneman::H0x0131000e_HitWithBones_01(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x0131000e
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x0131000f, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBoneman::H0x0131000f_HitWithBones_02(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x0131000f
;
#line 313 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(CalcDist  (m_penEnemy ) < BONES_HIT ){m_bFistHit  = TRUE ;}
#line 314 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soSound  , SOUND_PUNCH  , SOF_3D );
#line 315 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetTimerAfter(0.10f);
Jump(STATE_CURRENT, 0x01310010, FALSE, EBegin());return TRUE;}BOOL CBoneman::H0x01310010_HitWithBones_03(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310010
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01310011, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBoneman::H0x01310011_HitWithBones_04(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310011
;
#line 316 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(CalcDist  (m_penEnemy ) < BONES_HIT ){m_bFistHit  = TRUE ;}
#line 317 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(m_bFistHit ){
#line 318 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D vDirection  = m_penEnemy  -> GetPlacement  () . pl_PositionVector  - GetPlacement  () . pl_PositionVector ;
#line 319 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vDirection  . Normalize  ();
#line 321 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
InflictDirectDamage  (m_penEnemy  , this  , DMT_CLOSERANGE  , 10.0f , FLOAT3D (0 , 0 , 0) , vDirection );
#line 323 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D vSpeed ;
#line 324 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
GetHeadingDirection  (AngleDeg  (90.0f) , vSpeed );
#line 325 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vSpeed  = vSpeed  * 5.0f;
#line 326 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
KickEntity  (m_penEnemy  , vSpeed );
#line 327 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 330 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_bFistHit  = FALSE ;
#line 331 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetTimerAfter(0.25f);
Jump(STATE_CURRENT, 0x01310012, FALSE, EBegin());return TRUE;}BOOL CBoneman::H0x01310012_HitWithBones_05(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310012
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01310013, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBoneman::H0x01310013_HitWithBones_06(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310013
;
#line 332 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(CalcDist  (m_penEnemy ) < BONES_HIT ){m_bFistHit  = TRUE ;}
#line 333 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
PlaySound  (m_soSound  , SOUND_PUNCH  , SOF_3D );
#line 334 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetTimerAfter(0.10f);
Jump(STATE_CURRENT, 0x01310014, FALSE, EBegin());return TRUE;}BOOL CBoneman::H0x01310014_HitWithBones_07(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310014
switch(__eeInput.ee_slEvent) {case EVENTCODE_EBegin: return TRUE;case EVENTCODE_ETimer: Jump(STATE_CURRENT,0x01310015, FALSE, EInternal()); return TRUE;default: return FALSE; }}BOOL CBoneman::H0x01310015_HitWithBones_08(const CEntityEvent &__eeInput){
ASSERT(__eeInput.ee_slEvent==EVENTCODE_EInternal);
#undef STATE_CURRENT
#define STATE_CURRENT 0x01310015
;
#line 335 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(CalcDist  (m_penEnemy ) < BONES_HIT ){m_bFistHit  = TRUE ;}
#line 336 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(m_bFistHit ){
#line 338 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D vDirection  = m_penEnemy  -> GetPlacement  () . pl_PositionVector  - GetPlacement  () . pl_PositionVector ;
#line 339 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vDirection  . Normalize  ();
#line 340 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
InflictDirectDamage  (m_penEnemy  , this  , DMT_CLOSERANGE  , 10.0f , FLOAT3D (0 , 0 , 0) , vDirection );
#line 342 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
FLOAT3D vSpeed ;
#line 343 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
GetHeadingDirection  (AngleDeg  (- 90.0f) , vSpeed );
#line 344 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
vSpeed  = vSpeed  * 5.0f;
#line 345 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
KickEntity  (m_penEnemy  , vSpeed );
#line 346 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 347 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Return(STATE_CURRENT,EReturn  ());
#line 347 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
return TRUE; ASSERT(FALSE); return TRUE;};BOOL CBoneman::
#line 355 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Main(const CEntityEvent &__eeInput) {
#undef STATE_CURRENT
#define STATE_CURRENT STATE_CBoneman_Main
  ASSERTMSG(__eeInput.ee_slEvent==EVENTCODE_EVoid, "CBoneman::Main expects 'EVoid' as input!");  const EVoid &e = (const EVoid &)__eeInput;
#line 357 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
InitAsModel  ();
#line 358 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetPhysicsFlags  (EPF_MODEL_WALKING );
#line 359 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetCollisionFlags  (ECF_MODEL );
#line 360 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetFlags  (GetFlags  () | ENF_ALIVE );
#line 361 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetHealth  (125.0f);
#line 362 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fMaxHealth  = 125.0f;
#line 363 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
en_fDensity  = 2000.0f;
#line 366 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetModel  (MODEL_BONEMAN );
#line 367 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
SetModelMainTexture  (TEXTURE_BONEMAN );
#line 368 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
StandingAnim  ();
#line 369 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_sptType  = SPT_BONES ;
#line 371 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fWalkSpeed  = FRnd  () + 2.5f;
#line 372 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_aWalkRotateSpeed  = FRnd  () * 25.0f + 45.0f;
#line 373 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fAttackRunSpeed  = FRnd  () * 3.0f + 10.0f;
#line 374 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_aAttackRotateSpeed  = FRnd  () * 200 + 600.0f;
#line 375 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fCloseRunSpeed  = FRnd  () + 13.0f;
#line 376 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_aCloseRotateSpeed  = FRnd  () * 100 + 1000.0f;
#line 378 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fAttackDistance  = 100.0f;
#line 379 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fCloseDistance  = 30.0f;
#line 380 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fStopDistance  = 2.0f;
#line 381 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fAttackFireTime  = 3.0f;
#line 382 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fCloseFireTime  = 2.0f;
#line 383 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fIgnoreRange  = 200.0f;
#line 385 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fBlowUpAmount  = 70.0f;
#line 386 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fBodyParts  = 4;
#line 387 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fDamageWounded  = 80.0f;
#line 388 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_iScore  = 1000;
#line 389 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
if(m_fStepHeight  == - 1){
#line 390 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_fStepHeight  = 4.0f;
#line 391 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
}
#line 394 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
CEnemyBase  :: SizeModel  ();
#line 395 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_soFeet  . Set3DParameters  (80.0f , 5.0f , 1.0f , 1.0f);
#line 396 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
m_bRunSoundPlaying  = FALSE ;
#line 399 "D:/SE1_GPL/Sources/EntitiesMP/Boneman.es"
Jump(STATE_CURRENT, STATE_CEnemyBase_MainLoop, FALSE, EVoid());return TRUE; ASSERT(FALSE); return TRUE;};