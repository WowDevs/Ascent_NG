/*
 * Ascent MMORPG Server
 * Copyright (C) 2005-2011 Ascent Team <http://www.ascentemulator.net/>
 *
 * This software is  under the terms of the EULA License
 * All title, including but not limited to copyrights, in and to the Ascent Software
 * and any copies there of are owned by ZEDCLANS INC. or its suppliers. All title
 * and intellectual property rights in and to the content which may be accessed through
 * use of the Ascent is the property of the respective content owner and may be protected
 * by applicable copyright or other intellectual property laws and treaties. This EULA grants
 * you no rights to use such content. All rights not expressly granted are reserved by ZEDCLANS INC.
 *
 */

#ifndef _IVMAPMANAGER_H
#define _IVMAPMANAGER_H

#include <cstring>
#include <cstdlib>
#include<string>
class LocationVector;
//===========================================================

/**
This is the minimum interface to the VMapMamager.
*/

namespace VMAP
{

    enum VMAP_LOAD_RESULT
    {
        VMAP_LOAD_RESULT_ERROR,
        VMAP_LOAD_RESULT_OK,
        VMAP_LOAD_RESULT_IGNORED,
    };

    #define VMAP_INVALID_HEIGHT -100000.0f

    //===========================================================
    class IVMapManager
    {
        public:
            IVMapManager() {}

            virtual ~IVMapManager(void) {}

            virtual int loadMap(const char* pBasePath, unsigned int pMapId, int x, int y) = 0;

            virtual void unloadMap(unsigned int pMapId, int x, int y) = 0;
            virtual void unloadMap(unsigned int pMapId) = 0;

			// LOS
            virtual bool isInLineOfSight(unsigned int pMapId, float x1, float y1, float z1, float x2, float y2, float z2) = 0;
			virtual bool isInLineOfSight(unsigned int pMapId, LocationVector & v1, LocationVector & v2) = 0;

			// Height
            virtual float getHeight(unsigned int pMapId, float x, float y, float z) = 0;
			virtual float getHeight(unsigned int mapid, LocationVector & vec) = 0;

			// Indoors
			virtual bool isInDoors(unsigned int mapid, float x, float y, float z) = 0;
			virtual bool isInDoors(unsigned int mapid, LocationVector & vec) = 0;

			// Outdoors
			virtual bool isOutDoors(unsigned int mapid, float x, float y, float z) = 0;
			virtual bool isOutDoors(unsigned int mapid, LocationVector & vec) = 0;

            /**
            test if we hit an object. return true if we hit one. rx,ry,rz will hold the hit position or the dest position, if no intersection was found
            return a position, that is pReduceDist closer to the origin
            */

			// Closest Point
            virtual bool getObjectHitPos(unsigned int pMapId, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float &ry, float& rz, float pModifyDist) = 0;
			virtual bool getObjectHitPos(unsigned int pMapId, LocationVector & v1, LocationVector & v2, LocationVector & vout, float pModifyDist) = 0;


            virtual std::string getDirFileName(unsigned int pMapId, int x, int y) const =0;
    };

}
#endif
