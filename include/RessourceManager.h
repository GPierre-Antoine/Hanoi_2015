//
// Created by g20901528 on 07/10/15.
//



#pragma once

#include <memory>
#include <vector>
#include <utility>
#include "Cube.h"


typedef std::pair<std::unique_ptr<nsHanoi::Cube>, unsigned char> tCube;


namespace nsHanoi
{
    class RessourceManager
    {
    private:
        RessourceManager ();
        std::vector<tCube> vect;
        RessourceManager operator = (const RessourceManager &) = delete;
        RessourceManager (const RessourceManager &) = delete;
    public:
        static RessourceManager & getInstance () noexcept;
        void add(const Cube & elem) noexcept;
        void RenderAll() const noexcept;
        void Initialize_All_Cubes () noexcept;


    };
}