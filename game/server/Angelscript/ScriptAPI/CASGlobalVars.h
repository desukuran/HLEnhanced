#ifndef GAME_SERVER_ANGELSCRIPT_SCRIPTAPI_CASGLOBALS_H
#define GAME_SERVER_ANGELSCRIPT_SCRIPTAPI_CASGLOBALS_H

class asIScriptEngine;

/**
*	Registers the globalvars_t struct for Angelscript, called CGlobalVars.
*	@param engine Script engine.
*/
void RegisterScriptCGlobalVars( asIScriptEngine& engine );

#endif //GAME_SERVER_ANGELSCRIPT_SCRIPTAPI_CASGLOBALS_H