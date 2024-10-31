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

export function AccountSettingsScreen() {
  const { getGoTo, goTo } = useAppNavigation();
  const { user, setUser } = useAuthContext();

  const logout = () => {
    setUser(null);
    goTo("Login");
  };

  return (
    <Layout statusBarStyle="dark">
      <Layout.Header
        showLogo={false}
        backTo={null}
        onClose={getGoTo("Home", { screen: "HomeScreen" })}
      />
      <Text style={styles.title}>minha conta</Text>
      <View style={styles.settingsContainer}>
        {/* <Pressable style={styles.button}>
          <View style={styles.avatarContainer}>
            <Image
              style={styles.avatar}
              resizeMode="contain"
              source={require("@/assets/images/lock.png")}
            />
          </View>
          <Text style={styles.label}>redefinir senha</Text>
        </Pressable>
        <Pressable style={styles.button}>
          <View style={styles.avatarContainer}>
            <Image
              style={styles.avatar}
              resizeMode="contain"
              source={require("@/assets/images/pencil.png")}
            />
          </View>
          <Text style={styles.label}>editar nome de usuário</Text>
        </Pressable> */}
        <Pressable onPress={logout} style={styles.button}>
          <View style={styles.avatarContainer}>
            <Image
              style={styles.avatar}
              resizeMode="contain"
              source={require("@/assets/images/sign-out.png")}
            />
          </View>
          <Text style={styles.label}>sair</Text>
        </Pressable>
        {/* <Pressable style={styles.button}>
          <View style={styles.avatarContainer}>
            <Image
              style={styles.avatar}
              resizeMode="contain"
              source={require("@/assets/images/x.png")}
            />
          </View>
          <Text style={styles.label}>excluir conta</Text>
        </Pressable> */}
      </View>
    </Layout>
  );
}
