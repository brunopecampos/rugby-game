// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

int defender_movement_count = 0;
position_t attacker_spy_position;
position_t defender_my_position;
position_t defender_last_position;

direction_t defender_strategy_after_spy(position_t defender_position) {
  if(defender_position.i <= attacker_spy_position.i) return (direction_t) DIR_DOWN;
  return (direction_t ) DIR_UP;
}

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  if(defender_movement_count == 0) {
    defender_movement_count++;
    defender_last_position = defender_position;
    return (direction_t) DIR_UP;
  }
  if(defender_movement_count == 1) {
    defender_movement_count++;
    defender_last_position = defender_position;
    return (direction_t) DIR_DOWN;
  } 
  if(get_spy_number_uses(attacker_spy) == 0) {
    attacker_spy_position = get_spy_position(attacker_spy);
    defender_my_position = defender_position;
  }

      
  return defender_strategy_after_spy(defender_position);
}

/*----------------------------------------------------------------------------*/
