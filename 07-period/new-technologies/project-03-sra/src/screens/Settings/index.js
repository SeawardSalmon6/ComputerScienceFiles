import { APP_COLORS, APP_THEME } from "@/assets/theme";
import { Card } from "@/components/Card";
import { Layout } from "@/components/Layout";
import { QRCodeBox } from "@/components/QRCodeBox";
import { Slider } from "@/components/Slider";
import { useAuthContext } from "@/contexts/AuthContext/useAuthContext";
import { useThemeContext } from "@/contexts/ThemeContext/useThemeContext";
import { useAppNavigation } from "@/hooks/useAppNavigation";
import { styles } from "@/screens/Settings/styles";
import { Image, Pressable, Text, View } from "react-native";

export function SettingsScreen() {
  const { currentScheme, setCurrentScheme } = useThemeContext();
  const { getGoTo } = useAppNavigation();
  const { user } = useAuthContext();

  return (
    <Layout statusBarStyle="dark">
      <Layout.Header
        showLogo={false}
        onClose={getGoTo("Home", { screen: "HomeScreen" })}
        headerContentContainerStyle={styles.headerContainer}
      />
      <Text style={styles.title}>configurações</Text>
      <View style={styles.settingsContainer}>
        <Pressable onPress={getGoTo("AccountSettings")} style={styles.button}>
          <View style={styles.avatarContainer}>
            <Image
              style={styles.avatar}
              resizeMode="contain"
              source={require("@/assets/images/srazinho.png")}
            />
          </View>
          <Text style={styles.label}>minha conta</Text>
        </Pressable>
      </View>
      <Text style={styles.title}>preferências</Text>
      <View style={styles.settingsContainer}>
        <Pressable
          onPress={() =>
            setCurrentScheme(currentScheme === "light" ? "dark" : "light")
          }
          style={styles.button}
        >
          <Slider nestedButton value={currentScheme === "dark"} />
          <Text style={styles.label}>modo escuro</Text>
        </Pressable>
      </View>
      <View style={[styles.settingsContainer, styles.versionContainer]}>
        <Image
          style={styles.logo}
          resizeMode="contain"
          source={require("@/assets/icon.png")}
        />
        <Text style={styles.version}>v1.0</Text>
      </View>
    </Layout>
  );
}
