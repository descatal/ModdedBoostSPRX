#include "projectile_system.h"
#include "stdafx.h"
#include "unit_projectiles/hyaku_shiki.h"
#include "unit_projectiles/bael.h"
#include "unit_projectiles/exia.h"
#include "unit_projectiles/reborns.h"
#include "unit_projectiles/infinite_justice.h"
#include "unit_projectiles/bound_doc.h"
#include "unit_projectiles/quanta_full_saber.h"
#include "unit_projectiles/montero.h"
#include "unit_projectiles/barbatos_lupus_rex.h"
#include "unit_projectiles/barbatos_lupus.h"
#include "unit_projectiles/barbatos.h"
#include "unit_projectiles/raider_gundam.h"
#include "unit_projectiles/tallgeese_III.h"
#include "unit_projectiles/lacus_infinite_justice.h"
#include "unit_projectiles/nu_hws.h"
#include "unit_projectiles/perfect_strike.h"
#include "unit_projectiles/excellia.h"
#include "unit_projectiles/dark_hound.h"
#include "unit_projectiles/heine_destiny.h"
#include "unit_projectiles/kampfer.h"
#include "unit_projectiles/full_armor_gundam.h"
#include "unit_projectiles/kimaris_tropper.h"
#include "unit_projectiles/marasai.h"
#include "unit_projectiles/hyperion.h"
#include "unit_projectiles/age-1.h"
#include "unit_projectiles/age-3.h"
#include "unit_projectiles/leos_II_vs.h"
#include "unit_projectiles/gato_gelgoog.h"
#include "unit_projectiles/astray_red_frame_custom.h"
#include "unit_projectiles/phantom.h"
#include "unit_projectiles/double_x.h"
#include "unit_projectiles/infinite_justice_lacus.h"
#include "../registers.h"
#include "unit_projectiles/test.h"
#include "unit_projectiles/zabanya.h"
#include "unit_projectiles/age_fx.h"
#include "unit_projectiles/akautsuki.h"
#include "unit_projectiles/age-2.h"
#include "unit_projectiles/cherudim_gundam.h"
#include "unit_projectiles/crossbone_gundam_x2_custom.h"
#include "unit_projectiles/f91.h"
#include "unit_projectiles/fazz.h"
#include "unit_projectiles/gouf_ignited.h"
#include "unit_projectiles/gundam_legilis.h"
#include "unit_projectiles/gundam_x_divider.h"
#include "unit_projectiles/gunner_zaku_warrior.h"
#include "unit_projectiles/jagd_doga.h"
#include "unit_projectiles/mack_knife.h"
#include "unit_projectiles/sinanju.h"
#include "unit_projectiles/xi_gundam.h"
#include "unit_projectiles/zeydra.h"

int MBON_Added_Unit_ID[5000];
int custom_projectile_ID[5000];

void projectile_ID_Check_hook()
{
    printf("debug_projectile: %d \n", *(unsigned int*)lacus_infinite_justice_strike_freedom_following_assist_spawn);

    int projectile_ID = temp_registers[4];

    switch (projectile_ID)
    {
        case 0xc26:
            fazz_melee_assist_spawn();
            break;
        case 0xc3a:
            fazz_left_moving_shoot_assist_spawn();
            break;
        case 0xc3f:
            fazz_right_moving_shoot_assist_spawn();
            break;
        case 0x8c0: // Hyaku Shiki's rick dom assist spawn
            hyaku_shiki_rick_dias_spawn();
            break;
        case 0x105F:
            f91_melee_assist_spawn();
            break;
        case 0x1BF8:
            double_x_javelin_throw_spawn();
            break;
        case 0x1c8e:
            x_divider_melee_assist_spawn();
            break;
        case 0x1c93:
            x_divider_shoot_assist_spawn();
            break;
        case 0x1c94:
            x_divider_gerobi_assist_spawn();
            break;
        case 0x34C6:
            gato_gelgoog_naginata_throw_spawn();
            break;
        case 0x3746: // Exia EX Attack despawn
            exia_EX_Attack_despawn();
            break;
        case 0x3750: // Exia EX Attack despawn
            exia_EX_Attack_no_hit_despawn();
            break;
        case 0x3764:
            exia_dagger_throw_spawn();
            break;
        case 0x389b:
            cherudim_gundam_gerobi_assist_spawn();
            break;
        case 0x389C:
            cherudim_gundam_shoot_assist_spawn();
            break;
        case 0x3be4:
        case 0x3be7:
            sinanju_gerobi_assist_spawn();
            break;
        case 0x3BE2:
            sinanju_shoot_assist_spawn();
            break;
        case 0x42cc: // nu gundam's funnel, to be changed in the future.
            nu_hws_funnels_launch_spawn();
            break;
        case 0x514A:
            perfect_strike_hook_spawn();
            break;
        case 0x5140:
            perfect_strike_boomerang_spawn();
            break;
        case 0x5212:
            marasai_sword_throw_spawn();
            break;
        case 0x530c: // Infinite Justice EX Attack despawn
            infinite_justice_EX_Attack_despawn();
            break;
        case 0x55BE:
            infinite_justice_lacus_shoot_assist_spawn();
            break;
        case 0x53C0:
            gunner_zaku_warrior_gerobi_assist_spawn();
            break;
        case 0x53ca:
            gunner_zaku_warrior_melee_assist_spawn();
            break;
        case 0x5B36:
            crossbone_gundam_x2_custom_hook_spawn();
            break;
        case 0x7986:
            xi_gundam_melee_assist_spawn();
            break;
        case 0x798b:
            xi_gundam_shoot_assist_spawn();
            break;
        case 0x1D650:
            kampfer_chainmine_spawn();
            break;
        case 0x299AA:
            jagd_doga_shoot_assist_spawn();
            break;
        case 0x299B4:
            jagd_doga_melee_assist_spawn();
            break;
        case 0x338A6:
            gouf_ignited_melee_assist_spawn();
            break;
        case 0x3389C:
            gouf_ignited_shoot_assist_spawn();
            break;
        case 0x33964:
            heine_destiny_boomerang_spawn();
            break;
        case 0x3396e:
            heine_destiny_sword_throw_spawn();
            break;
        case 0x35D54:
            hyperion_sword_throw_spawn();
            break;
        case 0x35DB8:
        case 0x35DB9:
            astray_red_frame_custom_sword_throw_spawn();
            break;
        case 0x35DC2:
            astray_red_frame_custom_boomerang_throw_spawn();
            break;
        case 0x35DCC:
            astray_red_frame_custom_sword_wave_spawn();
            break;
        case 0x38464:
        case 0x3846E:
            phantom_sword_throw_spawn();
            break;
        case 0x50C30:
            dark_hound_sword_throw_spawn();
            break;
        case 0x50C3A:
            dark_hound_boomerang_spawn();
            break;
        case 0x50C4E:
            dark_hound_shoot_assist_spawn();
            break;
        case 0x50C62:
            dark_hound_melee_assist_spawn();
            break;
        case 0x50C76:
            dark_hound_hook_spawn();
            break;
        case 0x6699A:
            mack_knife_hook_spawn();
            break;
        case 0x77b3c: // Bael's CSa
            bael_CSa();
            break;
        case 0x77b46: // BC 2N derive, the stab
            bael_2BC();
            break;
        case 0x77b50: // BC 2N derive, the explosion
            bael_2BC_2();
            break;
        case 0xa05460:
            bound_doc_grab_shoot_hasei_sword_remain();
            break;
        case 0x4205e:
            quanta_full_saber_sword_throw_spawn_2();
            break;
        case 0x42068:
            quanta_full_saber_sword_throw_spawn();
            break;
        case 0x42072:
            quanta_full_saber_arrow_wave_beam_spawn();
            break;
        case 0x50974:
            age1_sword_throw_spawn();
            break;
        case 0x50992:
            age1_wave_spawn();
            break;
        case 0x509A1:
            age1_boomerang_throw_spawn();
            break;
        case 0x50988:
            age1_small_rock_throw_spawn();
            break;
        case 0x5098D:
            age1_big_rock_throw_spawn();
            break;
        case 0x509b3:
            age_1_melee_assist_spawn();
            break;
        case 0x50A50:
            age3_net_throw_spawn();
            break;
        case 0x50A5A:
            age_3_shoot_assist_spawn();
            break;
        case 0x50A5F:
            age_3_melee_assist_spawn();
            break;
        case 0x50ABE:
            age_fx_melee_assist_spawn();
            break;
        case 0x50ABF:
            age_fx_gerobi_assist_spawn();
            break;
        case 0x50B04:
        case 0x50B0E:
        case 0x50B18:
            zeydra_melee_assist_spawn();
            break;
        case 0x50BCC: // 
        case 0x50BE0: // neutral
        case 0x50BE5: // left / right
            gundam_legilis_bits_spawn();
            break;
        case 0x50C08:
            gundam_legilis_gerobi_assist_spawn();
            break;
        case 0x50C0d:
            gundam_legilis_funnel_assist_spawn();
            break;
        case 0x50C0E:
            gundam_legilis_fawn_farsia_funnel_spawn();
            break;
        case 0x53214:
        case 0x53246:
            excellia_boomerang_spawn();
            break;
        case 0x66a94:
            montero_JAVELIN_MADA_ARU_spawn();
            break;
        case 0x66a9e:
            montero_EX_Burst_Javelin_spawn();
            break;
        case 0x66abc:
            montero_wave_beam_spawn();
            break;
        case 0x66ad0:
            montero_G_Self_gerobi_shoot_spawn(); //montero_G_Self_shoot_melee_assist_spawn();
            break;
        case 0x66ac6:
            montero_G_Self_gerobi_shoot_spawn();
            break;
        case 0x69140:
            kimaris_trooper_mine_field_spawn();
            break;
        case 0x70544:
            full_armor_gundam_missile_spawn(false);
            break;
        case 0x70549:
            full_armor_gundam_missile_spawn(true);
            break;
        case 0x77bc8:
            barbatos_lupus_rex_tomahawk_throw_spawn();
            break;
        case 0x77bbe:
            barbatos_lupus_rex_mace_throw_spawn();
            break;
        case 0x77BDC:
            barbatos_lupus_rex_twin_shoot_assist_spawn();
            break;
        // case 0x77BD2:
        // 	barbatos_lupus_rex_grab_melee_assist_spawn();
        // 	break;
        case 0x77baa:
            barbatos_lupus_rex_tail_blade_one_time_spawn();
            break;
        case 0x77a88:
            barbatos_lupus_anti_ship_mace_spawn();
            break;
        case 0x77a7e:
            barbatos_lupus_twin_mace_throw_spawn();
            break;
        case 0x77AA6:
            barbatos_lupus_twin_shoot_assist_spawn();
            break;
        case 0x6903C:
            barbatos_mace_throw_spawn();
            break;
        case 0x69046:
            barbatos_ex_mace_throw_spawn();
            break;
        case 0x69037:
            barbatos_shoot_assist_spawn();
            break;
        case 0x69032:
            barbatos_melee_assist_spawn();
            break;
        case 0x31132:
            raider_nuclear_missile_spawn();
            break;
        case 0x531E2:
            leos_II_vs_wave_spawn();
            break;
        case 0x531F6:
            leos_II_vs_boomerang_throw_spawn();
            break;
        case 0xA00001:
            reborns_2ABC();
            break;
        case 0xA00002:
            reborns_Gaga_Assist();
            break;
        case 0xA00003:
            tallgeese_III_assist_spawn();
            break;
        case 0xA00004:
            lacus_infinite_justice_strike_freedom_following_assist_spawn();
            break;
        case 0xA00005:
            nu_gundam_hws_re_gz_shoot_assist_spawn();
            break;
        case 0xB00000:
            test_spawn();
            break;
        case 0x50A0F:
            age2_melee_assist_spawn();
            break;
        case 0x50A0A:
            age2_three_shoot_assist_spawn();
            break;
        case 0x420A4:
            Zabanya_Funnel_TypeNormal_spawn();
            break;
        case 0x50AB4:
            AGE_FX_Funnel_SwordType_spawn();
            break;
        case 0x33A72:
            akatsuki_NotMoveType_spawn();
            break;
        case 0x33A3B:
            akatsuki_NormalType_spawn();
            break;
        case 0x33A45:
            akatsuki_NormalType_spawn();
            break;
        case 0x33A40:
            akatsuki_NormalType_spawn();
            break;
        case 0x33A2C:
            akatsuki_NotMoveType_spawn();
            break;
        case 0x33A36:
            akatsuki_NormalType_spawn();
            break;
        default:
            break;
    }
}

void init_custom_projectile_ID()
{
    custom_projectile_ID[0] = 0x8c0;
    custom_projectile_ID[1] = 0x530c;
    custom_projectile_ID[2] = 0x3746;
    custom_projectile_ID[3] = 0x77b3c;
    custom_projectile_ID[4] = 0x77b46;
    custom_projectile_ID[5] = 0x77b50;
    custom_projectile_ID[6] = 0xa00001;
    custom_projectile_ID[7] = 0xa00002;
    custom_projectile_ID[8] = 0xa5460;
    custom_projectile_ID[9] = 0x3750;
    custom_projectile_ID[10] = 0x42072;
    custom_projectile_ID[11] = 0x4205e;
    custom_projectile_ID[12] = 0x42068;
    custom_projectile_ID[13] = 0x66a94;
    custom_projectile_ID[14] = 0x66a9e;
    custom_projectile_ID[15] = 0x66abc;
    custom_projectile_ID[16] = 0x66ad0;
    custom_projectile_ID[17] = 0x66ac6;
    custom_projectile_ID[18] = 0x77bc8;
    custom_projectile_ID[19] = 0x77bbe;
    custom_projectile_ID[20] = 0x77baa;
    custom_projectile_ID[21] = 0x77a88;
    custom_projectile_ID[22] = 0x77a7e;
    custom_projectile_ID[23] = 0x6903C;
    custom_projectile_ID[24] = 0x31132;
    custom_projectile_ID[25] = 0xA00003;
    custom_projectile_ID[26] = 0xA00004;
    custom_projectile_ID[27] = 0xA00005;
    custom_projectile_ID[28] = 0xA00006;
    custom_projectile_ID[29] = 0x5140;
    custom_projectile_ID[30] = 0x53214;
    custom_projectile_ID[31] = 0x50C3A;
    custom_projectile_ID[32] = 0x33964;
    custom_projectile_ID[33] = 0x69046;
    custom_projectile_ID[34] = 0x3764;
    custom_projectile_ID[35] = 0x3396E;
    custom_projectile_ID[36] = 0x50C30;
    custom_projectile_ID[37] = 0x1D650;
    custom_projectile_ID[38] = 0x70544;
    custom_projectile_ID[39] = 0x70549;
    custom_projectile_ID[40] = 0x69140;
    custom_projectile_ID[41] = 0x5212;
    custom_projectile_ID[42] = 0x35d54;
    custom_projectile_ID[43] = 0x509A1;
    custom_projectile_ID[44] = 0x50974;
    custom_projectile_ID[45] = 0x531E2;
    custom_projectile_ID[46] = 0x531F6;
    custom_projectile_ID[47] = 0x50992;
    custom_projectile_ID[48] = 0x50988;
    custom_projectile_ID[49] = 0x5098D;
    custom_projectile_ID[50] = 0x34C6;
    custom_projectile_ID[51] = 0x42CC; // nu gundam's funnel, to be changed in the future.
    custom_projectile_ID[52] = 0x50A50;
    custom_projectile_ID[53] = 0x35DB8;
    custom_projectile_ID[54] = 0x35DB9;
    custom_projectile_ID[55] = 0x35DC2;
    custom_projectile_ID[56] = 0x35DCC;
    custom_projectile_ID[57] = 0x3846E;
    custom_projectile_ID[58] = 0x38464;
    custom_projectile_ID[59] = 0x1BF8;
    custom_projectile_ID[60] = 0x55BE;
    custom_projectile_ID[61] = 0x53246;
    custom_projectile_ID[62] = 0x77AA6;
    custom_projectile_ID[63] = 0x77BDC;
    custom_projectile_ID[64] = 0x69037;
    custom_projectile_ID[65] = 0x69032;
    custom_projectile_ID[66] = 0x509B3;
    custom_projectile_ID[67] = 0x50A5A;
    custom_projectile_ID[68] = 0x50A5F;
    custom_projectile_ID[69] = 0x50B04;
    custom_projectile_ID[70] = 0x50B0E;
    custom_projectile_ID[71] = 0x50B18;
    custom_projectile_ID[72] = 0x1c8e;
    custom_projectile_ID[73] = 0x1c93;
    custom_projectile_ID[74] = 0x1c94;
    custom_projectile_ID[75] = 0x50C4E;
    custom_projectile_ID[76] = 0x50C62;
    custom_projectile_ID[77] = 0x105F;
    custom_projectile_ID[78] = 0x299AA;
    custom_projectile_ID[79] = 0x299B4;
    custom_projectile_ID[80] = 0x389b;
    custom_projectile_ID[81] = 0x389C;
    custom_projectile_ID[82] = 0x3be4;
    custom_projectile_ID[83] = 0x3BE7;
    custom_projectile_ID[84] = 0x3BE2;
    custom_projectile_ID[85] = 0x798b;
    custom_projectile_ID[86] = 0x7986;
    custom_projectile_ID[87] = 0x3389C;
    custom_projectile_ID[88] = 0x338A6;
    custom_projectile_ID[89] = 0x514A;
    custom_projectile_ID[90] = 0x50C76;
    custom_projectile_ID[91] = 0x5B36;
    custom_projectile_ID[92] = 0x53C0;
    custom_projectile_ID[93] = 0x53ca;
    custom_projectile_ID[94] = 0x6699A;
    custom_projectile_ID[95] = 0x50ABE;
    custom_projectile_ID[96] = 0x50ABF;
    custom_projectile_ID[97] = 0x50BCC;
    custom_projectile_ID[98] = 0x50BE0;
    custom_projectile_ID[99] = 0x50BE5;
    custom_projectile_ID[100] = 0xc26;
    custom_projectile_ID[101] = 0xc3a;
    custom_projectile_ID[102] = 0xc3f;
    custom_projectile_ID[103] = 0x50C08;
    custom_projectile_ID[104] = 0x50C0D;
    custom_projectile_ID[105] = 0x50C0E;
    
    //after 1000 is for other
    custom_projectile_ID[1000] = 0xB00000;
    custom_projectile_ID[1001] = 0x420A4;
    custom_projectile_ID[1002] = 0x50AB4;
    custom_projectile_ID[1003] = 0x33A72;
    custom_projectile_ID[1004] = 0x33A3B;
    custom_projectile_ID[1007] = 0x50A0F;
    custom_projectile_ID[1008] = 0x50A0A;
}


void init_MBON_Added_Unit_ID()
{
    MBON_Added_Unit_ID[0] = 0x425;
    MBON_Added_Unit_ID[1] = 0x80F3;
    MBON_Added_Unit_ID[2] = 0x80FD;
    MBON_Added_Unit_ID[3] = 0x13921;
    MBON_Added_Unit_ID[4] = 0x1392B;
    MBON_Added_Unit_ID[5] = 0xC31;
    MBON_Added_Unit_ID[6] = 0xC3B;
    MBON_Added_Unit_ID[7] = 0x4E71;
    MBON_Added_Unit_ID[8] = 0x524F;
    MBON_Added_Unit_ID[9] = 0x5623;
    MBON_Added_Unit_ID[10] = 0x5619;
    MBON_Added_Unit_ID[11] = 0x562D;
    MBON_Added_Unit_ID[12] = 0x6997;
    MBON_Added_Unit_ID[13] = 0x69AB;
    MBON_Added_Unit_ID[14] = 0x6DCF;
    MBON_Added_Unit_ID[15] = 0x6DD9;
    MBON_Added_Unit_ID[16] = 0x84F9;
    MBON_Added_Unit_ID[17] = 0x1395D;
    MBON_Added_Unit_ID[18] = 0x13967;
    MBON_Added_Unit_ID[19] = 0x13971;
    MBON_Added_Unit_ID[20] = 0x1397B;
    MBON_Added_Unit_ID[21] = 0x140B;
    MBON_Added_Unit_ID[22] = 0x5277;
    MBON_Added_Unit_ID[23] = 0x528B;
    MBON_Added_Unit_ID[24] = 0x835;
    MBON_Added_Unit_ID[25] = 0x373D;
    MBON_Added_Unit_ID[26] = 0x468D;
    MBON_Added_Unit_ID[27] = 0x4697;
    MBON_Added_Unit_ID[28] = 0x4E85;
    MBON_Added_Unit_ID[29] = 0x5A0B;
    MBON_Added_Unit_ID[30] = 0x69A1;
    MBON_Added_Unit_ID[31] = 0x8107;
    MBON_Added_Unit_ID[32] = 0x8111;
    MBON_Added_Unit_ID[33] = 0x811B;
    MBON_Added_Unit_ID[34] = 0x8125;
    MBON_Added_Unit_ID[35] = 0x13985;
    MBON_Added_Unit_ID[36] = 0x1398F;
    MBON_Added_Unit_ID[37] = 0x13999;
    MBON_Added_Unit_ID[38] = 0x139A3;
    MBON_Added_Unit_ID[39] = 0x65A5;
    MBON_Added_Unit_ID[40] = 0x812F;
    MBON_Added_Unit_ID[41] = 0x139B7;
    MBON_Added_Unit_ID[42] = 0x139C1;
    MBON_Added_Unit_ID[43] = 0x139CB;
    MBON_Added_Unit_ID[44] = 0x139D5;
    MBON_Added_Unit_ID[45] = 0x139DF;
    MBON_Added_Unit_ID[46] = 0x139E9;
    MBON_Added_Unit_ID[47] = 0x139F3;
    MBON_Added_Unit_ID[48] = 0x139FD;
    MBON_Added_Unit_ID[49] = 0x2F09;
    MBON_Added_Unit_ID[50] = 0x529F;
    MBON_Added_Unit_ID[51] = 0x8139;
    MBON_Added_Unit_ID[52] = 0x8503;
    MBON_Added_Unit_ID[53] = 0xA41B;
    MBON_Added_Unit_ID[54] = 0xA425;
    MBON_Added_Unit_ID[55] = 0xA42F;
    MBON_Added_Unit_ID[56] = 0xA803;
    MBON_Added_Unit_ID[57] = 0x139AD;
    MBON_Added_Unit_ID[58] = 0x4291;
    MBON_Added_Unit_ID[59] = 0xA439;
    MBON_Added_Unit_ID[60] = 0xB3BB;
    MBON_Added_Unit_ID[61] = 0x871;
    MBON_Added_Unit_ID[62] = 0xA821;
    MBON_Added_Unit_ID[63] = 0xB3C5;
    MBON_Added_Unit_ID[64] = 0x4E8F;
    MBON_Added_Unit_ID[65] = 0xCB2B;
    MBON_Added_Unit_ID[66] = 0xBF73;
    MBON_Added_Unit_ID[67] = 0xB3CF;
    MBON_Added_Unit_ID[68] = 0xBF7D;
    MBON_Added_Unit_ID[69] = 0xBF87;
    MBON_Added_Unit_ID[70] = 0xC743;
    MBON_Added_Unit_ID[71] = 0xA443;
    MBON_Added_Unit_ID[72] = 0xBF91;
    MBON_Added_Unit_ID[73] = 0xC74D;
}
