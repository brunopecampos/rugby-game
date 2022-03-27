// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

int attacker_movement_count = 0;
position_t defender_spy_position;
position_t attacker_my_position;
position_t attacker_last_position;

direction_t attacker_strategy_after_spy() {
  if(defender_spy_position.i <= attacker_my_position.i) return (direction_t) DIR_DOWN_RIGHT;
  if(defender_spy_position.i - attacker_my_position.i > 2) return (direction_t) DIR_RIGHT;
  return (direction_t) DIR_UP_RIGHT; 
} 

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {

  if(attacker_movement_count > 0) {
    if(equal_positions(attacker_position, attacker_last_position)) {
      if(attacker_position.i <= 1) return (direction_t) DIR_DOWN_RIGHT;
      return (direction_t) DIR_UP_RIGHT;
    }
  }
  attacker_movement_count++;
  if(attacker_movement_count < 4) {
    attacker_last_position = attacker_my_position;
    return (direction_t) DIR_UP_RIGHT;
  } 
  if(get_spy_number_uses(defender_spy) == 0) {
    defender_spy_position = get_spy_position(defender_spy);
    attacker_my_position = attacker_position;
  } 
  attacker_last_position = attacker_position;
  return attacker_strategy_after_spy(); 
}

/*----------------------------------------------------------------------------*/
