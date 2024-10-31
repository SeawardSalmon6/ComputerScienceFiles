import { APP_THEME } from "@/assets/theme";
import { DismissKeyboard } from "@/components/DismissKeyboard";
import { Header } from "@/components/Layout/Header";
import styles from "@/components/Layout/styles";
import { useThemeContext } from "@/contexts/ThemeContext/useThemeContext";
import { useEffect } from "react";
import { ScrollView, View } from "react-native";
import { SafeAreaView, useSafeAreaFrame } from "react-native-safe-area-context";

function Layout({
  children,
  rootStyle,
  contentContainerStyle,
  addExtraSpace,
  statusBarStyle = "light",
}) {
  const { height } = useSafeAreaFrame();
  const { setStatusBarStyle, colors } = useThemeContext();

  useEffect(() => {
    setStatusBarStyle(statusBarStyle);
  }, [statusBarStyle, setStatusBarStyle]);

  return (
    <DismissKeyboard>
      <View
        style={[
          {
            flex: 1,
            backgroundColor: colors.background,
          },
          rootStyle,
        ]}
      >
        <SafeAreaView style={styles.root}>
          <ScrollView
            contentContainerStyle={[
              styles.contentContainer,
              addExtraSpace && { paddingBottom: height / 3 },
              contentContainerStyle,
            ]}
          >
            {children}
          </ScrollView>
        </SafeAreaView>
      </View>
    </DismissKeyboard>
  );
}

Layout.Header = Header;

export { Layout };
