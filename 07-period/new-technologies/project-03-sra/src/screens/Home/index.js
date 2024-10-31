import { APP_COLORS, APP_THEME } from "@/assets/theme";
import { Card } from "@/components/Card";
import { Layout } from "@/components/Layout";
import { QRCodeBox } from "@/components/QRCodeBox";
import { useAuthContext } from "@/contexts/AuthContext/useAuthContext";
import { styles } from "@/screens/Home/styles";
import { Image, Text, View } from "react-native";

export function HomeScreen() {
  const { user } = useAuthContext();

  return (
    <Layout statusBarStyle="dark">
      <Layout.Header
        accessoryRight={
          <Layout.Header.Button
            icon={require("@/assets/images/notification.png")}
          />
        }
        containerStyle={styles.headerContainer}
      />
      <Card
        containerStyle={styles.cardContainer}
        backgroundColor={APP_COLORS.darkBlue}
      >
        <View style={styles.cardContentContainer}>
          <Image
            resizeMode="contain"
            style={styles.icon}
            source={require("@/assets/images/srazinho.png")}
          />
          <View style={styles.titleContainer}>
            <Text style={styles.title}>Olá {user?.name || "Maria Silva"}</Text>
            <Text style={styles.score}>{user?.score || 14800} pontos</Text>
          </View>
          <QRCodeBox />
          <Text style={styles.tip}>
            escaneie seu qrcode na catraca da entrada
          </Text>
        </View>
      </Card>
    </Layout>
  );
}
