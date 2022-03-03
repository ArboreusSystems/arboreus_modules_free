// ----------------------------------------------------------
/*!
	\headerfile
	\title
	\brief Template file files/cppheader/file.h

	\list
	\li @notice Template file classes/file.h
	\li @copyright Arboreus (http://arboreus.systems)
	\li @author Alexandr Kirilov (http://alexandr.kirilov.me)
	\li @created 01/05/2021 at 14:00:04
	\endlist
*/
// ----------------------------------------------------------
#ifndef ADBDATAMODELS_H
#define ADBDATAMODELS_H

// System includes

// Precompiled includes
#include <adbpch.h>

// Application includes

// Constants and defintions
#define _A_DB_NULL_VALUE "A_DB_NULL_VALUE"
#define _A_DB_TABLE_SCHEMA QList<ARB::ADBFieldProperties>

#define _A_ENUM_DB_SQLITE_FIELD_TYPE ARB::ADBFieldType::ADBSqliteFieldTypeEnum


// Namespace
namespace ARB {

class ADBFieldType: public QObject {

	Q_OBJECT

	public:

		enum class ADBSqliteFieldTypeEnum: int {

			Undefined,Null,Integer,
			Real,Text,Blob
		};
		Q_ENUM(ADBSqliteFieldTypeEnum)
};

} // namespace ARB

Q_DECLARE_METATYPE(_A_ENUM_DB_SQLITE_FIELD_TYPE)


namespace ARB {

class ADBProperties: public QObject {

	Q_OBJECT

	public:

		explicit ADBProperties(QObject* parent = nullptr) : QObject(parent) {}
		virtual ~ADBProperties(void) {}
};

class ADBSqliteProperties : public ADBProperties {

	public:

		QString Name = QString("NoName");
		QString Path = QString("NoPath");

		explicit ADBSqliteProperties(QObject* parent = nullptr) : ADBProperties(parent) {}
		virtual ~ADBSqliteProperties(void) {}
};

class ADBSqliteCipherProperties : public ADBSqliteProperties {

	public:

		QString Value = QString(_A_DB_NULL_VALUE);

		explicit ADBSqliteCipherProperties(QObject* parent = nullptr) : ADBSqliteProperties(parent) {}
		virtual ~ADBSqliteCipherProperties(void) {}
};

class ADBSqliteReply {

	public:

		bool Status = false;
		QVariantList Output = {};

		ADBSqliteReply(void) {}
		virtual ~ADBSqliteReply(void) {}

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("Status",Status);
			oOutput.insert("Output",Output);
			return oOutput;
		}
};

class ADBFieldProperties {

	public:

		_A_ENUM_DB_SQLITE_FIELD_TYPE Type = _A_ENUM_DB_SQLITE_FIELD_TYPE::Undefined;
		bool PrimaryKey = false;
		bool Autoincrement = false;
		bool Unique = false;
		bool NotNull = false;
		bool Default = false;
		QVariant DefaultValue = "NoDefaultValue";
		QString Name = "NoDefinedFieldName";
		QString UserName = "NoDefinedFieldUserName";

		ADBFieldProperties(void) {}
		virtual ~ADBFieldProperties(void) {}


		// -----------
		/*!
			\fn

			Doc.
		*/

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("Type",QVariant::fromValue(Type));
			oOutput.insert("PrimaryKey",PrimaryKey);
			oOutput.insert("Autoincrement",Autoincrement);
			oOutput.insert("Unique",Unique);
			oOutput.insert("NotNull",NotNull);
			oOutput.insert("Default",Default);
			oOutput.insert("DefaultValue",DefaultValue);
			oOutput.insert("Name",Name);
			oOutput.insert("UserName",UserName);
			return oOutput;
		}


		// -----------
		/*!
			\fn

			Doc.
		*/

		void mFromVariantMap(QVariantMap inProperties) {

			QString oErrorValue = "ErrorDBFieldValue";
			QVariant oValue;

			oValue = inProperties.value("Type",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				Type = qvariant_cast<_A_ENUM_DB_SQLITE_FIELD_TYPE>(oValue);
			}

			oValue = inProperties.value("PrimaryKey",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				PrimaryKey = qvariant_cast<bool>(oValue);
			}

			oValue = inProperties.value("Autoincrement",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				Autoincrement = qvariant_cast<bool>(oValue);
			}

			oValue = inProperties.value("Unique",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				Unique = qvariant_cast<bool>(oValue);
			}

			oValue = inProperties.value("NotNull",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				NotNull = qvariant_cast<bool>(oValue);
			}

			oValue = inProperties.value("Default",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				Default = qvariant_cast<bool>(oValue);
			}

			oValue = inProperties.value("DefaultValue",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				DefaultValue = oValue;
			}

			oValue = inProperties.value("Name",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				Name = qvariant_cast<QString>(oValue);
			}

			oValue = inProperties.value("UserName",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				UserName = qvariant_cast<QString>(oValue);
			}
		}
};

class ADBTableProperties {

	public:

		QString Name = "NoDefinedTableName";
		QList<ADBFieldProperties> Schema = {};

		ADBTableProperties(void) {}
		virtual ~ADBTableProperties(void) {}


		// -----------
		/*!
			\fn

			Doc.
		*/

		QVariantMap mToVariantMap(void) {

			QVariantList oSchema;
			foreach (ADBFieldProperties iField, Schema) {
				oSchema.append(iField.mToVariantMap());
			}

			QVariantMap oOutput;
			oOutput.insert("Name",Name);
			oOutput.insert("Schema",oSchema);
			return oOutput;
		}


		// -----------
		/*!
			\fn

			Doc.
		*/

		void mFromVariantMap(QVariantMap inSchema) {

			QString oErrorValue = "ErrorDBFieldValue";
			QVariant oValue;

			oValue = inSchema.value("Name",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				Name = qvariant_cast<QString>(oValue);
			}

			oValue = inSchema.value("Schema",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				QVariantList oSchema = qvariant_cast<QVariantList>(oValue);
				foreach (QVariant iField, oSchema) {
					ADBFieldProperties iFieldProperties;
					iFieldProperties.mFromVariantMap(qvariant_cast<QVariantMap>(iField));
					Schema.append(iFieldProperties);
				}
			}
		}
};

class ASqlInsertProperties {

	public:

		QString TableName = "NoTableName";
		QVariantList Data = {};

		explicit ASqlInsertProperties(void) {}
		virtual ~ASqlInsertProperties(void) {}

		QVariantMap mToVariantMap(void) {

			QVariantMap oOutput;
			oOutput.insert("TableName",TableName);
			oOutput.insert("Data",Data);
			return oOutput;
		}

		void mFromVariantMap(QVariantMap inProperties) {

			QString oErrorValue = "ErrorDBFieldValue";
			QVariant oValue;

			oValue = inProperties.value("TableName",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				TableName = qvariant_cast<QString>(oValue);
			}

			oValue = inProperties.value("Data",oErrorValue);
			if (QString::compare(oErrorValue,qvariant_cast<QString>(oValue)) != 0) {
				Data = qvariant_cast<QVariantList>(oValue);
			}
		}
};

class ASqlUpdateProperties {


	public:

		explicit ASqlUpdateProperties(void) {}
		virtual ~ASqlUpdateProperties(void) {}
};

} //namespace ARB

#endif // ADBDATAMODELS_H
