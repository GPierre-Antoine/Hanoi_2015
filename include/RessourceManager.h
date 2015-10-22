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
        const float biggest_disk = 4.f;
        const float offset = 1.f;
        const int square = 1;

        const int number_of_disks = 5;

        const float disk_height = 1.f;

        const float half = square/2;

        const float base_height = 1.f;

        const int number_of_pikes = 3;

        const float delta_decrease = 0.5f;


        RessourceManager ();
        std::vector<tCube> vect;
        RessourceManager operator = (const RessourceManager &) = delete;
        RessourceManager (const RessourceManager &) = delete;
    public:

        void setView() noexcept;
        static RessourceManager & getInstance () noexcept;
        void add(const Cube & elem) noexcept;
        void RenderAll() const noexcept;
        void Initialize_All_Cubes () noexcept;


    };
}