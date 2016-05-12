/*    Copyright (c) 2010-2016, Delft University of Technology
 *    All rigths reserved
 *
 *    This file is part of the Tudat. Redistribution and use in source and
 *    binary forms, with or without modification, are permitted exclusively
 *    under the terms of the Modified BSD license. You should have received
 *    a copy of the license with this file. If not, please or visit:
 *    http://tudat.tudelft.nl/LICENSE.
 */

#ifndef TUDAT_DEFAULTBODIES_H
#define TUDAT_DEFAULTBODIES_H

#include "Tudat/SimulationSetup/createBodies.h"

namespace tudat
{

namespace simulation_setup
{

//! Function to create default settings for a body's atmosphere model.
/*!
 *  Function to create default settings for a body's atmosphere model. Currently set to no
 *  atmosphere, except for Earth, for which a tabulated version of the 1976 Standard Atmosphere is
 *  set.
 *  \param bodyName Name of body for which default atmosphere settings are to be retrieved.
 *  \param initialTime Start time at which environment models in body are to be created
 *  (not currently used by this function, but included for consistency).
 *  \param finalTime End time up to which environment models in body are to be created
 *  (not currently used by this function, but included for consistency).
 *  \return Default settings for a body's atmosphere model.
 */
boost::shared_ptr< AtmosphereSettings > getDefaultAtmosphereModelSettings(
        const std::string& bodyName,
        const double initialTime,
        const double finalTime );

//! Function to create default settings for a body's ephemeris.
/*!
 *  Function to create default settings for a body's ephemeris. Currently set to a
 *  creating a 6th order Lagrange interpolator from Spice, with a 300 s time step.
 *  \param bodyName Name of body for which default ephemeris settings are to be retrieved.
 *  \param initialTime Start time at which ephemeris is to be created.
 *  \param finalTime End time up to which ephemeris is to be created.
 *  \return Default settings for a body's ephemeris.
 */
boost::shared_ptr< EphemerisSettings > getDefaultEphemerisSettings(
        const std::string& bodyName,
        const double initialTime,
        const double finalTime );

//! Function to create default settings for a body's gravity field model.
/*!
 *  Function to create default settings for a body's gravity field model. Currently set to
 *  a point mass gravty field, with the gravitational parameter obtained from Spice.
 *  \param bodyName Name of body for which default gravity field settings are to be retrieved.
 *  \param initialTime Start time at which environment models in body are to be created
 *  (not currently used by this function, but included for consistency).
 *  \param finalTime End time up to which environment models in body are to be created
 *  (not currently used by this function, but included for consistency).
 *  \return Default settings for a body's gravity field model.
 */
boost::shared_ptr< GravityFieldSettings > getDefaultGravityFieldSettings(
        const std::string& bodyName,
        const double initialTime,
        const double finalTime );

//! Function to create default settings for a body's rotation model.
/*!
 *  Function to create default settings for a body's rotation model. Currently set to
 *  a rotation model taken directly from Spice
 *  \param bodyName Name of body for which default rotation model settings are to be retrieved.
 *  \param initialTime Start time at which environment models in body are to be created
 *  (not currently used by this function, but included for consistency).
 *  \param finalTime End time up to which environment models in body are to be created
 *  (not currently used by this function, but included for consistency).
 *  \return Default settings for a body's rotation model.
 */
boost::shared_ptr< RotationModelSettings > getDefaultRotationModelSettings(
        const std::string& bodyName,
        const double initialTime,
        const double finalTime );

//! Function to create default settings from which to create a single body object.
/*!
 *  Function to create default settings from which to create a single body object using
 *  the code in createBodies.h/.cpp. This function is included to streamline and simplify the
 *  creation of typical celestial bodies. The default settings for the various
 *  environment models of the body are defined in the various functions defined in this file.
 *  \param bodyName Name of body for which default settings are to be retrieved.
 *  \param initialTime Start time at which environment models in body are to be created
 *  (included as some environment models require e.g., interpolators to be created over
 *  a certain time period).
 *  \param finalTime End time up to which environment models in body are to be created
 *  (included as some environment models require e.g., interpolators to be created over
 *  a certain time period).
 *  \return Default settings from which to create a single body object.
 */
boost::shared_ptr< RotationModelSettings > getDefaultRotationModelSettings(
        const std::string& bodyName,
        const double initialTime,
        const double finalTime );

//! Function to create default settings from which to create a set of body objects.
/*!
 *  Function to create default settings from which to create a set of body objects using
 *  the code in createBodies.h/.cpp. This function is included to streamline and simplify the
 *  creation of typical celestial bodies. The default settings for the various
 *  environment models of the body are defined in the various functions defined in this file.
 *  \param bodies List of bodies for which default settings are to be retrieved.
 *  \param initialTime Start time at which environment models in body are to be created
 *  (included as some environment models require e.g., interpolators to be created over
 *  a certain time period).
 *  \param finalTime End time up to which environment models in body are to be created
 *  (included as some environment models require e.g., interpolators to be created over
 *  a certain time period).
 *  \return Default settings from which to create a set of body objects.
 */
std::map< std::string, boost::shared_ptr< BodySettings > > getDefaultBodySettings(
        const std::vector< std::string >& bodies,
        const double initialTime,
        const double finalTime );

} // namespace simulation_setup

} // namespace tudat

#endif // TUDAT_DEFAULTBODIES_H
