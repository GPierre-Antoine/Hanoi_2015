//
// Created by g20901528 on 07/10/15.
//



#pragma once

#include <memory>
#include <vector>
#include <utility>
#include <cstddef>
#include "Cube.h"
#include "Pike.h"
#include "Disc.h"

namespace nsHanoi
{
    class RessourceManager
    {
    private:
        RessourceManager ();
        Cube *support;
        std::vector<Disc> disks;
        std::vector<Pike> cols;
        RessourceManager operator = (const RessourceManager &) = delete;
        RessourceManager (const RessourceManager &) = delete;

    public:
        static constexpr float biggest_disk = 4.f  ;
        static constexpr float offset = 1.f;
        static constexpr unsigned int square = 1;

        static constexpr unsigned int number_of_disks = 5;

        static constexpr float disk_height = 1.f;

        static constexpr float half = square/2;

        static constexpr float base_height = 1.f;

        static constexpr unsigned int number_of_pikes = 3;

        static constexpr float delta_decrease = 0.5f;


        void setView() noexcept;
        static RessourceManager & getInstance () noexcept;
        void add(const Cube & elem) noexcept;
        void RenderAll() const noexcept;
        void Initialize_All_Cubes () noexcept;

        void Algorithme ();
        void HanoiA (unsigned int nbdisk,std::size_t origine,std::size_t dest,std::size_t intermediaire);

        ~RessourceManager ();
    };
}