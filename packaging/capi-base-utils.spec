Name:       capi-base-utils
Summary:    Base Utils
Version:    1.1.1
Release:    1
Group:      Base
License:    Apache-2.0 and ICU
Source0:    %{name}-%{version}.tar.gz
BuildRequires:  cmake
BuildRequires:  pkgconfig(icu-i18n)
BuildRequires:  pkgconfig(capi-base-common)
BuildRequires:  pkgconfig(dlog)

Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
	
%description
The base utils library for internationalization and localization

%package devel
License:    Apache-2.0 and ICU
Summary:    The Base Utils Library (Development)
Group:      Base
Requires:   %{name} = %{version}-%{release}

%description devel
The base utils library for internationalization and localization (Development)

%prep
%setup -q

%build
#export CFLAGS="$CFLAGS -Wall -Werror -Wno-unused-function"
cmake . -DCMAKE_INSTALL_PREFIX=%{_prefix} -DLIB_INSTALL_DIR:PATH=%{_libdir} -DINCLUDE_INSTALL_DIR:PATH=%{_includedir} \
    -DPKG_NAME=%{name} -DPKG_VERSION=%{version} \
%if "%{profile}" == "wearable"
    -DTIZEN_WEARABLE=YES \
%endif
%if "%{profile}" == "mobile"
    -DTIZEN_MOBILE=YES \
%endif

make %{?jobs:-j%jobs}

%install
rm -rf %{buildroot}
%make_install
mkdir -p %{buildroot}/usr/share/license
cp LICENSE %{buildroot}/usr/share/license/%{name}
cat LICENSE.ICU >> %{buildroot}/usr/share/license/%{name}

%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%manifest capi-base-utils.manifest
%{_libdir}/libbase-utils-i18n.so*
/usr/share/license/%{name}

%files devel
%defattr(-,root,root,-)
%{_includedir}/base/utils_i18n_ucalendar.h
%{_includedir}/base/utils_i18n_udate.h
%{_includedir}/base/utils_i18n_udatepg.h
%{_includedir}/base/utils_i18n_ulocale.h
%{_includedir}/base/utils_i18n_unumber.h
%{_includedir}/base/utils_i18n_uchar.h
%{_includedir}/base/utils_i18n_ucollator.h
%{_includedir}/base/utils_i18n_unormalization.h
%{_includedir}/base/utils_i18n_usearch.h
%{_includedir}/base/utils_i18n_ustring.h
%{_includedir}/base/utils_i18n_timezone.h
%{_includedir}/base/utils_i18n_types.h
%{_includedir}/base/utils_i18n_uenumeration.h
%{_includedir}/base/utils_i18n_uset.h
%{_includedir}/base/utils_i18n_ubrk.h
%{_includedir}/base/utils_i18n.h
%{_libdir}/pkgconfig/*.pc
