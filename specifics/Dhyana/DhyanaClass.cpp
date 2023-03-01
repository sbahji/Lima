/*----- PROTECTED REGION ID(DhyanaClass.cpp) ENABLED START -----*/
static const char *RcsId      = "$Id:  $";
static const char *TagName    = "$Name:  $";
static const char *CvsPath    = "$Source:  $";
static const char *SvnPath    = "$HeadURL:  $";
static const char *HttpServer = "http://www.esrf.eu/computing/cs/tango/tango_doc/ds_doc/";
//=============================================================================
//
// file :        DhyanaClass.cpp
//
// description : C++ source for the DhyanaClass.
//               A singleton class derived from DeviceClass.
//               It implements the command and attribute list
//               and all properties and methods required
//               by the Dhyana once per process.
//
// project :     Device specific for Dhyana detector
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifdef WIN32
#include "tango.h"
#endif
#include <Dhyana.h>
#include <DhyanaClass.h>

#ifndef WIN32
#include "tango.h"
#endif

/*----- PROTECTED REGION END -----*/	//	DhyanaClass.cpp

//-------------------------------------------------------------------
/**
 *	Create DhyanaClass singleton and
 *	return it in a C function for Python usage
 */
//-------------------------------------------------------------------
extern "C" {
#ifdef _TG_WINDOWS_

__declspec(dllexport)

#endif

	Tango::DeviceClass *_create_Dhyana_class(const char *name) {
		return Dhyana_ns::DhyanaClass::init(name);
	}
}

namespace Dhyana_ns
{
//===================================================================
//	Initialize pointer for singleton pattern
//===================================================================
DhyanaClass *DhyanaClass::_instance = NULL;

//--------------------------------------------------------
/**
 * method : 		DhyanaClass::DhyanaClass(string &s)
 * description : 	constructor for the DhyanaClass
 *
 * @param s	The class name
 */
//--------------------------------------------------------
DhyanaClass::DhyanaClass(string &s):Tango::DeviceClass(s)
{
	cout2 << "Entering DhyanaClass constructor" << endl;
	set_default_property();
	write_class_property();

	/*----- PROTECTED REGION ID(DhyanaClass::constructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::constructor

	cout2 << "Leaving DhyanaClass constructor" << endl;
}

//--------------------------------------------------------
/**
 * method : 		DhyanaClass::~DhyanaClass()
 * description : 	destructor for the DhyanaClass
 */
//--------------------------------------------------------
DhyanaClass::~DhyanaClass()
{
	/*----- PROTECTED REGION ID(DhyanaClass::destructor) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::destructor

	_instance = NULL;
}


//--------------------------------------------------------
/**
 * method : 		DhyanaClass::init
 * description : 	Create the object if not already done.
 *                  Otherwise, just return a pointer to the object
 *
 * @param	name	The class name
 */
//--------------------------------------------------------
DhyanaClass *DhyanaClass::init(const char *name)
{
	if (_instance == NULL)
	{
		try
		{
			string s(name);
			_instance = new DhyanaClass(s);
		}
		catch (bad_alloc &)
		{
			throw;
		}
	}
	return _instance;
}

//--------------------------------------------------------
/**
 * method : 		DhyanaClass::instance
 * description : 	Check if object already created,
 *                  and return a pointer to the object
 */
//--------------------------------------------------------
DhyanaClass *DhyanaClass::instance()
{
	if (_instance == NULL)
	{
		cerr << "Class is not initialised !!" << endl;
		exit(-1);
	}
	return _instance;
}



//===================================================================
//	Command execution method calls
//===================================================================

//===================================================================
//	Properties management
//===================================================================
//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::get_class_property()
 *	Description : Get the class property for specified name.
 */
//--------------------------------------------------------
Tango::DbDatum DhyanaClass::get_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_prop.size() ; i++)
		if (cl_prop[i].name == prop_name)
			return cl_prop[i];
	//	if not found, returns  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::get_default_device_property()
 *	Description : Return the default value for device property.
 */
//--------------------------------------------------------
Tango::DbDatum DhyanaClass::get_default_device_property(string &prop_name)
{
	for (unsigned int i=0 ; i<dev_def_prop.size() ; i++)
		if (dev_def_prop[i].name == prop_name)
			return dev_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}

//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::get_default_class_property()
 *	Description : Return the default value for class property.
 */
//--------------------------------------------------------
Tango::DbDatum DhyanaClass::get_default_class_property(string &prop_name)
{
	for (unsigned int i=0 ; i<cl_def_prop.size() ; i++)
		if (cl_def_prop[i].name == prop_name)
			return cl_def_prop[i];
	//	if not found, return  an empty DbDatum
	return Tango::DbDatum(prop_name);
}


//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::set_default_property()
 *	Description : Set default property (class and device) for wizard.
 *                For each property, add to wizard property name and description.
 *                If default value has been set, add it to wizard property and
 *                store it in a DbDatum.
 */
//--------------------------------------------------------
void DhyanaClass::set_default_property()
{
	string	prop_name;
	string	prop_desc;
	string	prop_def;
	vector<string>	vect_data;

	//	Set Default Class Properties

	//	Set Default device Properties
	prop_name = "TemperatureTargetAtInit";
	prop_desc = "Memorize/Define the temperatureTarget  attribute  at Init device<br>";
	prop_def  = "15";
	vect_data.clear();
	vect_data.push_back("15");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "MemorizedFanSpeed";
	prop_desc = "Memorize/Define the fanSpeed  attribute  at Init device<br>";
	prop_def  = "1";
	vect_data.clear();
	vect_data.push_back("1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "MemorizedGlobalGain";
	prop_desc = "Memorize/Define the globalGain  attribute  at Init device<br>";
	prop_def  = "LOW";
	vect_data.clear();
	vect_data.push_back("LOW");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
	prop_name = "__ExpertTimerPeriod";
	prop_desc = "Timer period in ms.<cr>\nuseful only for Internal Trigger";
	prop_def  = "1";
	vect_data.clear();
	vect_data.push_back("1");
	if (prop_def.length()>0)
	{
		Tango::DbDatum	data(prop_name);
		data << vect_data ;
		dev_def_prop.push_back(data);
		add_wiz_dev_prop(prop_name, prop_desc,  prop_def);
	}
	else
		add_wiz_dev_prop(prop_name, prop_desc);
}

//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::write_class_property()
 *	Description : Set class description fields as property in database
 */
//--------------------------------------------------------
void DhyanaClass::write_class_property()
{
	//	First time, check if database used
	if (Tango::Util::_UseDb == false)
		return;

	Tango::DbData	data;
	string	classname = get_name();
	string	header;
	string::size_type	start, end;

	//	Put title
	Tango::DbDatum	title("ProjectTitle");
	string	str_title("Device specific for Dhyana detector");
	title << str_title;
	data.push_back(title);

	//	Put Description
	Tango::DbDatum	description("Description");
	vector<string>	str_desc;
	str_desc.push_back("Interface the camera Dhyana using  the TUCAM Library");
	description << str_desc;
	data.push_back(description);

	//  Put inheritance
	Tango::DbDatum	inher_datum("InheritedFrom");
	vector<string> inheritance;
	inheritance.push_back("TANGO_BASE_CLASS");
	inher_datum << inheritance;
	data.push_back(inher_datum);

	//	Call database and and values
	get_db_class()->put_property(data);
}

//===================================================================
//	Factory methods
//===================================================================

//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::device_factory()
 *	Description : Create the device object(s)
 *                and store them in the device list
 */
//--------------------------------------------------------
void DhyanaClass::device_factory(const Tango::DevVarStringArray *devlist_ptr)
{
	/*----- PROTECTED REGION ID(DhyanaClass::device_factory_before) ENABLED START -----*/
	
	//	Add your own code

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new Dhyana(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	//erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		Dhyana *dev = static_cast<Dhyana *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	return;
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::device_factory_before

	//	Create devices and add it into the device list
	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		cout4 << "Device name : " << (*devlist_ptr)[i].in() << endl;
		device_list.push_back(new Dhyana(this, (*devlist_ptr)[i]));
	}

	//	Manage dynamic attributes if any
	erase_dynamic_attributes(devlist_ptr, get_class_attr()->get_attr_list());

	//	Export devices to the outside world
	for (unsigned long i=1 ; i<=devlist_ptr->length() ; i++)
	{
		//	Add dynamic attributes if any
		Dhyana *dev = static_cast<Dhyana *>(device_list[device_list.size()-i]);
		dev->add_dynamic_attributes();

		//	Check before if database used.
		if ((Tango::Util::_UseDb == true) && (Tango::Util::_FileDb == false))
			export_device(dev);
		else
			export_device(dev, dev->get_name().c_str());
	}

	/*----- PROTECTED REGION ID(DhyanaClass::device_factory_after) ENABLED START -----*/

	

	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::device_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::attribute_factory()
 *	Description : Create the attribute object(s)
 *                and store them in the attribute list
 */
//--------------------------------------------------------
void DhyanaClass::attribute_factory(vector<Tango::Attr *> &att_list)
{
	/*----- PROTECTED REGION ID(DhyanaClass::attribute_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::attribute_factory_before
	//	Attribute : tucamVersion
	tucamVersionAttrib	*tucamversion = new tucamVersionAttrib();
	Tango::UserDefaultAttrProp	tucamversion_prop;
	tucamversion_prop.set_description("Dhyana Tucam Version.");
	//	label	not set for tucamVersion
	tucamversion_prop.set_unit("  ");
	tucamversion_prop.set_standard_unit("  ");
	tucamversion_prop.set_display_unit("  ");
	//	format	not set for tucamVersion
	//	max_value	not set for tucamVersion
	//	min_value	not set for tucamVersion
	//	max_alarm	not set for tucamVersion
	//	min_alarm	not set for tucamVersion
	//	max_warning	not set for tucamVersion
	//	min_warning	not set for tucamVersion
	//	delta_t	not set for tucamVersion
	//	delta_val	not set for tucamVersion
	
	tucamversion->set_default_properties(tucamversion_prop);
	//	Not Polled
	tucamversion->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(tucamversion);

	//	Attribute : temperature
	temperatureAttrib	*temperature = new temperatureAttrib();
	Tango::UserDefaultAttrProp	temperature_prop;
	temperature_prop.set_description("Get Temperature of the detector (in Celsius)");
	//	label	not set for temperature
	temperature_prop.set_unit("Celsius");
	//	standard_unit	not set for temperature
	//	display_unit	not set for temperature
	//	format	not set for temperature
	//	max_value	not set for temperature
	//	min_value	not set for temperature
	//	max_alarm	not set for temperature
	//	min_alarm	not set for temperature
	//	max_warning	not set for temperature
	//	min_warning	not set for temperature
	//	delta_t	not set for temperature
	//	delta_val	not set for temperature
	
	temperature->set_default_properties(temperature_prop);
	//	Not Polled
	temperature->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(temperature);

	//	Attribute : temperatureTarget
	temperatureTargetAttrib	*temperaturetarget = new temperatureTargetAttrib();
	Tango::UserDefaultAttrProp	temperaturetarget_prop;
	temperaturetarget_prop.set_description("Set the Temperature target of the detector (in Celsius)");
	//	label	not set for temperatureTarget
	temperaturetarget_prop.set_unit("Celsius");
	//	standard_unit	not set for temperatureTarget
	//	display_unit	not set for temperatureTarget
	//	format	not set for temperatureTarget
	//	max_value	not set for temperatureTarget
	//	min_value	not set for temperatureTarget
	//	max_alarm	not set for temperatureTarget
	//	min_alarm	not set for temperatureTarget
	//	max_warning	not set for temperatureTarget
	//	min_warning	not set for temperatureTarget
	//	delta_t	not set for temperatureTarget
	//	delta_val	not set for temperatureTarget
	
	temperaturetarget->set_default_properties(temperaturetarget_prop);
	//	Not Polled
	temperaturetarget->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(temperaturetarget);

	//	Attribute : fanSpeed
	fanSpeedAttrib	*fanspeed = new fanSpeedAttrib();
	Tango::UserDefaultAttrProp	fanspeed_prop;
	fanspeed_prop.set_description("Define the fan speed of the detector [0..5]");
	//	label	not set for fanSpeed
	//	unit	not set for fanSpeed
	//	standard_unit	not set for fanSpeed
	//	display_unit	not set for fanSpeed
	//	format	not set for fanSpeed
	//	max_value	not set for fanSpeed
	//	min_value	not set for fanSpeed
	//	max_alarm	not set for fanSpeed
	//	min_alarm	not set for fanSpeed
	//	max_warning	not set for fanSpeed
	//	min_warning	not set for fanSpeed
	//	delta_t	not set for fanSpeed
	//	delta_val	not set for fanSpeed
	
	fanspeed->set_default_properties(fanspeed_prop);
	//	Not Polled
	fanspeed->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(fanspeed);

	//	Attribute : globalGain
	globalGainAttrib	*globalgain = new globalGainAttrib();
	Tango::UserDefaultAttrProp	globalgain_prop;
	globalgain_prop.set_description("Define the gain of the detector [LOW, HIGH, HDR]");
	//	label	not set for globalGain
	//	unit	not set for globalGain
	//	standard_unit	not set for globalGain
	//	display_unit	not set for globalGain
	//	format	not set for globalGain
	//	max_value	not set for globalGain
	//	min_value	not set for globalGain
	//	max_alarm	not set for globalGain
	//	min_alarm	not set for globalGain
	//	max_warning	not set for globalGain
	//	min_warning	not set for globalGain
	//	delta_t	not set for globalGain
	//	delta_val	not set for globalGain
	
	globalgain->set_default_properties(globalgain_prop);
	//	Not Polled
	globalgain->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(globalgain);

	//	Attribute : fps
	fpsAttrib	*fps = new fpsAttrib();
	Tango::UserDefaultAttrProp	fps_prop;
	fps_prop.set_description("The last computed frame per second (the value is computed every 100 frames only)");
	fps_prop.set_label("FPS");
	//	unit	not set for fps
	//	standard_unit	not set for fps
	//	display_unit	not set for fps
	fps_prop.set_format("%.2f");
	//	max_value	not set for fps
	//	min_value	not set for fps
	//	max_alarm	not set for fps
	//	min_alarm	not set for fps
	//	max_warning	not set for fps
	//	min_warning	not set for fps
	//	delta_t	not set for fps
	//	delta_val	not set for fps
	
	fps->set_default_properties(fps_prop);
	//	Not Polled
	fps->set_disp_level(Tango::OPERATOR);
	//	Not Memorized
	att_list.push_back(fps);

	//	Attribute : channel1
	channel1Attrib	*channel1 = new channel1Attrib();
	Tango::UserDefaultAttrProp	channel1_prop;
	//	description	not set for channel1
	//	label	not set for channel1
	//	unit	not set for channel1
	//	standard_unit	not set for channel1
	//	display_unit	not set for channel1
	//	format	not set for channel1
	//	max_value	not set for channel1
	//	min_value	not set for channel1
	//	max_alarm	not set for channel1
	//	min_alarm	not set for channel1
	//	max_warning	not set for channel1
	//	min_warning	not set for channel1
	//	delta_t	not set for channel1
	//	delta_val	not set for channel1
	
	channel1->set_default_properties(channel1_prop);
	//	Not Polled
	channel1->set_disp_level(Tango::EXPERT);
	channel1->set_memorized();
	channel1->set_memorized_init(true);
	att_list.push_back(channel1);

	//	Attribute : channel2
	channel2Attrib	*channel2 = new channel2Attrib();
	Tango::UserDefaultAttrProp	channel2_prop;
	//	description	not set for channel2
	//	label	not set for channel2
	//	unit	not set for channel2
	//	standard_unit	not set for channel2
	//	display_unit	not set for channel2
	//	format	not set for channel2
	//	max_value	not set for channel2
	//	min_value	not set for channel2
	//	max_alarm	not set for channel2
	//	min_alarm	not set for channel2
	//	max_warning	not set for channel2
	//	min_warning	not set for channel2
	//	delta_t	not set for channel2
	//	delta_val	not set for channel2
	
	channel2->set_default_properties(channel2_prop);
	//	Not Polled
	channel2->set_disp_level(Tango::EXPERT);
	channel2->set_memorized();
	channel2->set_memorized_init(true);
	att_list.push_back(channel2);

	//	Attribute : channel3
	channel3Attrib	*channel3 = new channel3Attrib();
	Tango::UserDefaultAttrProp	channel3_prop;
	//	description	not set for channel3
	//	label	not set for channel3
	//	unit	not set for channel3
	//	standard_unit	not set for channel3
	//	display_unit	not set for channel3
	//	format	not set for channel3
	//	max_value	not set for channel3
	//	min_value	not set for channel3
	//	max_alarm	not set for channel3
	//	min_alarm	not set for channel3
	//	max_warning	not set for channel3
	//	min_warning	not set for channel3
	//	delta_t	not set for channel3
	//	delta_val	not set for channel3
	
	channel3->set_default_properties(channel3_prop);
	//	Not Polled
	channel3->set_disp_level(Tango::EXPERT);
	channel3->set_memorized();
	channel3->set_memorized_init(true);
	att_list.push_back(channel3);

	//	Attribute : width1
	width1Attrib	*width1 = new width1Attrib();
	Tango::UserDefaultAttrProp	width1_prop;
	//	description	not set for width1
	//	label	not set for width1
	width1_prop.set_unit("ms");
	//	standard_unit	not set for width1
	//	display_unit	not set for width1
	//	format	not set for width1
	//	max_value	not set for width1
	//	min_value	not set for width1
	//	max_alarm	not set for width1
	//	min_alarm	not set for width1
	//	max_warning	not set for width1
	//	min_warning	not set for width1
	//	delta_t	not set for width1
	//	delta_val	not set for width1
	
	width1->set_default_properties(width1_prop);
	//	Not Polled
	width1->set_disp_level(Tango::EXPERT);
	width1->set_memorized();
	width1->set_memorized_init(true);
	att_list.push_back(width1);

	//	Attribute : width2
	width2Attrib	*width2 = new width2Attrib();
	Tango::UserDefaultAttrProp	width2_prop;
	//	description	not set for width2
	//	label	not set for width2
	width2_prop.set_unit("ms");
	//	standard_unit	not set for width2
	//	display_unit	not set for width2
	//	format	not set for width2
	//	max_value	not set for width2
	//	min_value	not set for width2
	//	max_alarm	not set for width2
	//	min_alarm	not set for width2
	//	max_warning	not set for width2
	//	min_warning	not set for width2
	//	delta_t	not set for width2
	//	delta_val	not set for width2
	
	width2->set_default_properties(width2_prop);
	//	Not Polled
	width2->set_disp_level(Tango::EXPERT);
	width2->set_memorized();
	width2->set_memorized_init(true);
	att_list.push_back(width2);

	//	Attribute : width3
	width3Attrib	*width3 = new width3Attrib();
	Tango::UserDefaultAttrProp	width3_prop;
	//	description	not set for width3
	//	label	not set for width3
	width3_prop.set_unit("ms");
	//	standard_unit	not set for width3
	//	display_unit	not set for width3
	//	format	not set for width3
	//	max_value	not set for width3
	//	min_value	not set for width3
	//	max_alarm	not set for width3
	//	min_alarm	not set for width3
	//	max_warning	not set for width3
	//	min_warning	not set for width3
	//	delta_t	not set for width3
	//	delta_val	not set for width3
	
	width3->set_default_properties(width3_prop);
	//	Not Polled
	width3->set_disp_level(Tango::EXPERT);
	width3->set_memorized();
	width3->set_memorized_init(true);
	att_list.push_back(width3);

	//	Attribute : delay1
	delay1Attrib	*delay1 = new delay1Attrib();
	Tango::UserDefaultAttrProp	delay1_prop;
	//	description	not set for delay1
	//	label	not set for delay1
	delay1_prop.set_unit("ms");
	//	standard_unit	not set for delay1
	//	display_unit	not set for delay1
	//	format	not set for delay1
	//	max_value	not set for delay1
	//	min_value	not set for delay1
	//	max_alarm	not set for delay1
	//	min_alarm	not set for delay1
	//	max_warning	not set for delay1
	//	min_warning	not set for delay1
	//	delta_t	not set for delay1
	//	delta_val	not set for delay1
	
	delay1->set_default_properties(delay1_prop);
	//	Not Polled
	delay1->set_disp_level(Tango::EXPERT);
	delay1->set_memorized();
	delay1->set_memorized_init(true);
	att_list.push_back(delay1);

	//	Attribute : delay2
	delay2Attrib	*delay2 = new delay2Attrib();
	Tango::UserDefaultAttrProp	delay2_prop;
	//	description	not set for delay2
	//	label	not set for delay2
	delay2_prop.set_unit("ms");
	//	standard_unit	not set for delay2
	//	display_unit	not set for delay2
	//	format	not set for delay2
	//	max_value	not set for delay2
	//	min_value	not set for delay2
	//	max_alarm	not set for delay2
	//	min_alarm	not set for delay2
	//	max_warning	not set for delay2
	//	min_warning	not set for delay2
	//	delta_t	not set for delay2
	//	delta_val	not set for delay2
	
	delay2->set_default_properties(delay2_prop);
	//	Not Polled
	delay2->set_disp_level(Tango::EXPERT);
	delay2->set_memorized();
	delay2->set_memorized_init(true);
	att_list.push_back(delay2);

	//	Attribute : delay3
	delay3Attrib	*delay3 = new delay3Attrib();
	Tango::UserDefaultAttrProp	delay3_prop;
	//	description	not set for delay3
	//	label	not set for delay3
	delay3_prop.set_unit("ms");
	//	standard_unit	not set for delay3
	//	display_unit	not set for delay3
	//	format	not set for delay3
	//	max_value	not set for delay3
	//	min_value	not set for delay3
	//	max_alarm	not set for delay3
	//	min_alarm	not set for delay3
	//	max_warning	not set for delay3
	//	min_warning	not set for delay3
	//	delta_t	not set for delay3
	//	delta_val	not set for delay3
	
	delay3->set_default_properties(delay3_prop);
	//	Not Polled
	delay3->set_disp_level(Tango::EXPERT);
	delay3->set_memorized();
	delay3->set_memorized_init(true);
	att_list.push_back(delay3);

	//	Attribute : edge1
	edge1Attrib	*edge1 = new edge1Attrib();
	Tango::UserDefaultAttrProp	edge1_prop;
	//	description	not set for edge1
	//	label	not set for edge1
	//	unit	not set for edge1
	//	standard_unit	not set for edge1
	//	display_unit	not set for edge1
	//	format	not set for edge1
	//	max_value	not set for edge1
	//	min_value	not set for edge1
	//	max_alarm	not set for edge1
	//	min_alarm	not set for edge1
	//	max_warning	not set for edge1
	//	min_warning	not set for edge1
	//	delta_t	not set for edge1
	//	delta_val	not set for edge1
	
	edge1->set_default_properties(edge1_prop);
	//	Not Polled
	edge1->set_disp_level(Tango::EXPERT);
	edge1->set_memorized();
	edge1->set_memorized_init(true);
	att_list.push_back(edge1);

	//	Attribute : edge2
	edge2Attrib	*edge2 = new edge2Attrib();
	Tango::UserDefaultAttrProp	edge2_prop;
	//	description	not set for edge2
	//	label	not set for edge2
	//	unit	not set for edge2
	//	standard_unit	not set for edge2
	//	display_unit	not set for edge2
	//	format	not set for edge2
	//	max_value	not set for edge2
	//	min_value	not set for edge2
	//	max_alarm	not set for edge2
	//	min_alarm	not set for edge2
	//	max_warning	not set for edge2
	//	min_warning	not set for edge2
	//	delta_t	not set for edge2
	//	delta_val	not set for edge2
	
	edge2->set_default_properties(edge2_prop);
	//	Not Polled
	edge2->set_disp_level(Tango::EXPERT);
	edge2->set_memorized();
	edge2->set_memorized_init(true);
	att_list.push_back(edge2);

	//	Attribute : edge3
	edge3Attrib	*edge3 = new edge3Attrib();
	Tango::UserDefaultAttrProp	edge3_prop;
	//	description	not set for edge3
	//	label	not set for edge3
	//	unit	not set for edge3
	//	standard_unit	not set for edge3
	//	display_unit	not set for edge3
	//	format	not set for edge3
	//	max_value	not set for edge3
	//	min_value	not set for edge3
	//	max_alarm	not set for edge3
	//	min_alarm	not set for edge3
	//	max_warning	not set for edge3
	//	min_warning	not set for edge3
	//	delta_t	not set for edge3
	//	delta_val	not set for edge3
	
	edge3->set_default_properties(edge3_prop);
	//	Not Polled
	edge3->set_disp_level(Tango::EXPERT);
	edge3->set_memorized();
	edge3->set_memorized_init(true);
	att_list.push_back(edge3);


	//	Create a list of static attributes
	create_static_attribute_list(get_class_attr()->get_attr_list());
	/*----- PROTECTED REGION ID(DhyanaClass::attribute_factory_after) ENABLED START -----*/
	
	channel1Attrib *triggerout1 = new channel1Attrib();
	Tango::UserDefaultAttrProp triggerout1_prop;
	vector<string> triggerout_labels = {"ExposureStart", "Readout", "Global"};
	triggerout1_prop.set_enum_labels(triggerout_labels);
	triggerout1->set_default_properties(triggerout1_prop);
	att_list.push_back(triggerout1);

	channel2Attrib *triggerout2 = new channel2Attrib();
	Tango::UserDefaultAttrProp triggerout2_prop;
	triggerout2_prop.set_enum_labels(triggerout_labels);
	triggerout2->set_default_properties(triggerout2_prop);
	att_list.push_back(triggerout2);

	channel3Attrib *triggerout3 = new channel3Attrib();
	Tango::UserDefaultAttrProp triggerout3_prop;
	triggerout3_prop.set_enum_labels(triggerout_labels);
	triggerout3->set_default_properties(triggerout3_prop);
	att_list.push_back(triggerout3);
	

	edge1Attrib *edgeout1 = new edge1Attrib();
	Tango::UserDefaultAttrProp edgeout1_prop;
	vector<string> edge_labels = {"Raising", "Failing"};
	edgeout1_prop.set_enum_labels(edge_labels);
	edgeout1->set_default_properties(edgeout1_prop);
	att_list.push_back(edgeout1);

	edge2Attrib *edgeout2 = new edge2Attrib();
	Tango::UserDefaultAttrProp edgeout2_prop;
	edgeout2_prop.set_enum_labels(edge_labels);
	edgeout2->set_default_properties(edgeout2_prop);
	att_list.push_back(edgeout2);

	edge3Attrib *edgeout3 = new edge3Attrib();
	Tango::UserDefaultAttrProp edgeout3_prop;
	edgeout3_prop.set_enum_labels(edge_labels);
	edgeout3->set_default_properties(edgeout3_prop);
	att_list.push_back(edgeout3);
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::attribute_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::pipe_factory()
 *	Description : Create the pipe object(s)
 *                and store them in the pipe list
 */
//--------------------------------------------------------
void DhyanaClass::pipe_factory()
{
	/*----- PROTECTED REGION ID(DhyanaClass::pipe_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::pipe_factory_before
	/*----- PROTECTED REGION ID(DhyanaClass::pipe_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::pipe_factory_after
}
//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::command_factory()
 *	Description : Create the command object(s)
 *                and store them in the command list
 */
//--------------------------------------------------------
void DhyanaClass::command_factory()
{
	/*----- PROTECTED REGION ID(DhyanaClass::command_factory_before) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::command_factory_before


	/*----- PROTECTED REGION ID(DhyanaClass::command_factory_after) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::command_factory_after
}

//===================================================================
//	Dynamic attributes related methods
//===================================================================

//--------------------------------------------------------
/**
 * method : 		DhyanaClass::create_static_attribute_list
 * description : 	Create the a list of static attributes
 *
 * @param	att_list	the ceated attribute list
 */
//--------------------------------------------------------
void DhyanaClass::create_static_attribute_list(vector<Tango::Attr *> &att_list)
{
	for (unsigned long i=0 ; i<att_list.size() ; i++)
	{
		string att_name(att_list[i]->get_name());
		transform(att_name.begin(), att_name.end(), att_name.begin(), ::tolower);
		defaultAttList.push_back(att_name);
	}

	cout2 << defaultAttList.size() << " attributes in default list" << endl;

	/*----- PROTECTED REGION ID(DhyanaClass::create_static_att_list) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::create_static_att_list
}


//--------------------------------------------------------
/**
 * method : 		DhyanaClass::erase_dynamic_attributes
 * description : 	delete the dynamic attributes if any.
 *
 * @param	devlist_ptr	the device list pointer
 * @param	list of all attributes
 */
//--------------------------------------------------------
void DhyanaClass::erase_dynamic_attributes(const Tango::DevVarStringArray *devlist_ptr, vector<Tango::Attr *> &att_list)
{
	Tango::Util *tg = Tango::Util::instance();

	for (unsigned long i=0 ; i<devlist_ptr->length() ; i++)
	{
		Tango::DeviceImpl *dev_impl = tg->get_device_by_name(((string)(*devlist_ptr)[i]).c_str());
		Dhyana *dev = static_cast<Dhyana *> (dev_impl);

		vector<Tango::Attribute *> &dev_att_list = dev->get_device_attr()->get_attribute_list();
		vector<Tango::Attribute *>::iterator ite_att;
		for (ite_att=dev_att_list.begin() ; ite_att != dev_att_list.end() ; ++ite_att)
		{
			string att_name((*ite_att)->get_name_lower());
			if ((att_name == "state") || (att_name == "status"))
				continue;
			vector<string>::iterator ite_str = find(defaultAttList.begin(), defaultAttList.end(), att_name);
			if (ite_str == defaultAttList.end())
			{
				cout2 << att_name << " is a UNWANTED dynamic attribute for device " << (*devlist_ptr)[i] << endl;
				Tango::Attribute &att = dev->get_device_attr()->get_attr_by_name(att_name.c_str());
				dev->remove_attribute(att_list[att.get_attr_idx()], true, false);
				--ite_att;
			}
		}
	}
	/*----- PROTECTED REGION ID(DhyanaClass::erase_dynamic_attributes) ENABLED START -----*/
	
	/*----- PROTECTED REGION END -----*/	//	DhyanaClass::erase_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Method      : DhyanaClass::get_attr_object_by_name()
 *	Description : returns Tango::Attr * object found by name
 */
//--------------------------------------------------------
Tango::Attr *DhyanaClass::get_attr_object_by_name(vector<Tango::Attr *> &att_list, string attname)
{
	vector<Tango::Attr *>::iterator it;
	for (it=att_list.begin() ; it<att_list.end() ; ++it)
		if ((*it)->get_name()==attname)
			return (*it);
	//	Attr does not exist
	return NULL;
}


/*----- PROTECTED REGION ID(DhyanaClass::Additional Methods) ENABLED START -----*/

/*----- PROTECTED REGION END -----*/	//	DhyanaClass::Additional Methods
} //	namespace
